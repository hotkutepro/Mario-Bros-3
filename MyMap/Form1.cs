using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MyMap
{
    public partial class Form1 : Form
    {
        int _column = 0;//số phần tử trên một dòng
        int _row = 0;//số phần tử trên một cột
        int _width = 0;//chiều dài của phần tử
        int _height = 0;//chiều rộng của phần tử
        int[,] _arrmap;
        int _index = -1;
        Queue<Rectangle> qRectDest = new Queue<Rectangle>();        

        List<Button> _lObject = new List<Button>();//danh sách các đối tượng thể hiện bên phải cửa sổ
        List<OinMap> _lTiled = new List<OinMap>();//các đối tượng được vẽ trên map
        List<TextBox> _lNameObject = new List<TextBox>();
        List<Label> _lIdObject = new List<Label>();
        Bitmap _img;
        Bitmap _dest;        
        tiled _tiled = new tiled();
        Image _image;       
        Size _sizeObject;

        public Form1()
        {
            InitializeComponent();            
        }
        public void createmap()
        {
            _arrmap = new int[_row, _column];
            List<tiled> listtiled = new List<tiled>();

            for (int i = 0; i < _column; i++)
                for (int j = 0; j < _row; j++)
                    listtiled.Add(new tiled(new Rectangle(i * _width, j * _height, _width, _height), new Point(j, i)));
            int index = 0;
            while (listtiled.Count != 0)
            {
                tiled tmp = listtiled[0];
                listtiled.RemoveAt(0);
                qRectDest.Enqueue(tmp.rec);
                _arrmap[tmp.point.X, tmp.point.Y] = index;
                int i = 0;
                while (i < listtiled.Count)
                {
                    tiled t = listtiled[i];
                   // if (checkPixels(tmp.rec, t.rec))
                    if(checkPixels_Neo(tmp.rec,t.rec))
                    {
                        _arrmap[t.point.X, t.point.Y] = index;
                        listtiled.Remove(t);
                        i--;
                    }
                    i++;
                }
                index++;
            }
        }
        private void writemap(string filename)
        {
            using (var stream = new FileStream(filename + ".txt", FileMode.Create, FileAccess.Write, FileShare.None))
            using (var writer = new StreamWriter(stream))
            {
                writer.Write(_row + " " + _column + "\r\n");
                for (int i = _row-1; i>=0 ; i--)
                {
                    for (int j = 0; j < _column; j++)
                    {
                        ///////////////////////////
                        writer.Write(_arrmap[i, j] + " ");
                    }
                    writer.Write("\r\n");
                }
                writer.Close();
            }
        }
        private bool checkPixels_Neo(Rectangle r1, Rectangle r2) {
            Color cl1, cl2;
            for (int i = 0; i < _width; i++)
            {
                cl1 = this._img.GetPixel(r1.Left + i, r1.Top + i);
                cl2 = this._img.GetPixel(r2.Left + i, r2.Top + i);
                if (cl1 != cl2)
                    return false;
                cl1 = this._img.GetPixel(r1.Left + i, r1.Bottom - i-1);
                cl2 = this._img.GetPixel(r2.Left + i, r2.Bottom - i-1);
                if (cl1 != cl2)
                    return false;
            }
            return true;
        }
        private bool checkPixels(Rectangle r1, Rectangle r2)
        {
            Color[] cl1 = new Color[_width * _height];
            Color[] cl2 = new Color[_width * _height];
            int k = 0;            
           for (int i = r1.Left; i < r1.Right; i++)
                for (int j = r1.Top; j < r1.Bottom; j++)
                {
                    cl1[k++] = this._img.GetPixel(i, j);
                }
             k = 0;                
            for (int i = r2.Left; i < r2.Right; i++)
                for (int j = r2.Top; j < r2.Bottom; j++)
                {
                    cl2[k++] = this._img.GetPixel(i, j);
                }
            for (int i = 0; i < _width * _height; i++)
                if (cl1[i] != cl2[i])
                    return false;
                return true;
        }
        private void drawMap()
        {
            int i = 0;
            _dest = new Bitmap(qRectDest.Count * _width, _height);
            foreach (Rectangle r in qRectDest)
            {
                Rectangle rDest = new Rectangle(i++ * _width, 0, _width, _height);
                using (Graphics g = Graphics.FromImage(_dest))
                {
                    g.DrawImage(_img, rDest, r, GraphicsUnit.Pixel);
                }
            }
        }
        private void saveTiledMap(string filename)
        {
            string outputFileName = filename + ".Png";
            using (MemoryStream ms = new MemoryStream())
            {
                using (FileStream fs = new FileStream(outputFileName, FileMode.Create, FileAccess.ReadWrite))
                {
                    _dest.Save(ms, ImageFormat.Png);
                    byte[] bytes = ms.ToArray();
                    fs.Write(bytes, 0, bytes.Length);
                }
            }
        }                                
        private void tbtw_KeyPress(object sender, KeyPressEventArgs e)
        {
            e.Handled = !((e.KeyChar >= 48 && e.KeyChar <= 57) || e.KeyChar == 8);
        }
        private void tbth_KeyPress(object sender, KeyPressEventArgs e)
        {
            e.Handled = !((e.KeyChar >= 48 && e.KeyChar <= 57) || e.KeyChar == 8);
        }       
        private void btbrowses_Click(object sender, EventArgs e)
        {                        
            try
            {                
                OpenFileDialog openFile = new OpenFileDialog();
                openFile.Filter = "Image|*.jpg;*.png;*.bmp;*.jpeg;*.gif";
                if (openFile.ShowDialog() == System.Windows.Forms.DialogResult.OK)                
                {
                    tbsourse.Text = openFile.FileName;
                    Bitmap img = new Bitmap(tbsourse.Text);
                    lbimfomation.Text = "W = " + img.Width + " H = " + img.Height;                    
                }
            }
            catch
            {
                MessageBox.Show("Nhập lại đường dẫn của file ảnh");
            }            
        }        
        private void btBrowsesI_Click(object sender, EventArgs e)
        {
            FolderBrowserDialog fbd = new FolderBrowserDialog();
            if (fbd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                tbnoiluuim.Text = fbd.SelectedPath;
            }
        }
        private void btDuyet_Click(object sender, EventArgs e)
        {
	            createmap();
            writemap(tbnoiluuim.Text + "\\" + tbIn.Text);
            drawMap();
            saveTiledMap(tbnoiluuim.Text + "\\" + tbIn.Text);
            MessageBox.Show("Đã Căt Xong! Tới đường dẫn " + tbnoiluuim.Text + " để xem kết quả");
            cbCoordinatesMouse.Enabled = true;
        }
        
        private void _btAddtiled_Click(object sender, EventArgs e)
        {            
            OpenFileDialog openFile = new OpenFileDialog();
            openFile.Filter = "Image|*.jpg;*.png;*.bmp;*.jpeg;*.gif";
            if (openFile.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                Button tmp = new Button();
                tmp.Size = _sizeObject;
                tmp.Image = Image.FromFile(openFile.FileName);
                //mỗi đối tượng Object(bên phải cửa sổ ) sẽ có tên riêng để phân biệt và tên riêng cũng chính là số thứ tự trong list
                tmp.Name = ""+_lObject.Count;
                tmp.Location = new Point(10,100+ _lObject.Count * _height);
                tmp.MouseClick += new MouseEventHandler(Tiled_MouseClick);
                _lObject.Add(tmp);                
                panel2.Controls.Add(_lObject[_lObject.Count-1]);


                TextBox tbm = new TextBox();
                tbm.Size = new Size(64, 20);
                tbm.Name = "" + _lNameObject.Count;
                tbm.Location = new Point(_lObject[_lObject.Count - 1].Location.X + _lObject[_lObject.Count - 1].Size.Width + 35, _lObject[_lObject.Count - 1].Location.Y);
                _lNameObject.Add(tbm);
                panel2.Controls.Add(_lNameObject[_lNameObject.Count - 1]);

                Label lbm = new Label();
                lbm.Size = new Size(25,20);
                lbm.Text = "Id";
                lbm.Location= new Point(_lObject[_lObject.Count - 1].Location.X + _lObject[_lObject.Count - 1].Size.Width + 20, _lObject[_lObject.Count - 1].Location.Y);
                _lIdObject.Add(lbm);
                panel2.Controls.Add(_lIdObject[_lIdObject.Count-1]);
                btnGetObject.Enabled = true;                   
            }            
        }
        void Tiled_MouseClick(object sender, MouseEventArgs e)////lấy chỉ số của đối tượng bên phải
        {
            Button t = (Button)sender;
            foreach (Button i in _lObject)
            {
                if (t.Name == i.Name)
                {                    
                    _index = int.Parse(i.Name);
                }
            }

        }
        
        public class tiled
        {
            private Rectangle _rec;
            public System.Drawing.Rectangle rec
            {
                get { return _rec; }
                set { _rec = value; }
            }
            private Point _point;
            public System.Drawing.Point point
            {
                get { return _point; }
                set { _point = value; }
            }
            public tiled()
            {
                _rec = new Rectangle();
                _point = new Point();
            }
            public tiled(Rectangle rec, Point point)
            {
                this._rec = rec;
                this._point = point;
            }
        }

        private void btnKiemTra_Click(object sender, EventArgs e)
        {

            if(tbsourse.Text=="")
            {
                MessageBox.Show("Vui lòng nhập đường dẫn của file ảnh");
                return;
            }            
            if(tbIn.Text=="")
            {
                MessageBox.Show("Vui lòng nhập Tên của ảnh sau khi cắt");
                return;
            }
            if (tbtw.Text == "" || tbth.Text == "")
            {
                MessageBox.Show("Vui lòng nhập kích thước của một đối tượng ảnh");
                return;
            }
            int w = int.Parse(tbtw.Text); 
            int h = int.Parse(tbth.Text);
            _img = new Bitmap(tbsourse.Text);
            if (_img.Width % w != 0 || _img.Height % h != 0)
            {
                MessageBox.Show("Kiểm tra lại kích thước của một frame ảnh ");
                return;
            }            
            _image = Image.FromFile(tbsourse.Text);
            this._width = int.Parse(tbtw.Text);
            this._height = int.Parse(tbth.Text);
            this._column = _img.Width / _width;
            this._row = _img.Height / _height;
            pbImage.Image = _image;
            pbImage.Enabled = true;
            btDuyet.Enabled = true;
            btAddtiled.Enabled = true;
            _sizeObject = new Size(_width, _height);
            panel1.MinimumSize = new Size(_img.Width, _img.Height);
            pbImage.MinimumSize = new Size(_img.Width, _img.Height);
            for(int i=0;i<_row;i++)
                for(int j=0;j<_column;j++)
                {
                    OinMap tbm = new OinMap();
                    tbm.Visible = false;
                    tbm.Size = _sizeObject;
                    tbm.Name = "" + (j + i * _column);
                    tbm.Location = new Point(pbImage.Location.X + j * _width + 2, pbImage.Location.Y + i * _height + 2);
                    tbm.MouseClick += new MouseEventHandler(l_btnTiled_MouseClick);
                    _lTiled.Add(tbm);                    
                }
            this.pbImage.Paint += new System.Windows.Forms.PaintEventHandler(this.pbImage_Paint);
        }
        private void l_btnTiled_MouseClick(object sender, MouseEventArgs e)
        {
            if (_index != -2)
                return;
            Button t = (Button)sender;
            int i = int.Parse(t.Name);
            _lTiled[i].Image = null;
            _lTiled[i].id = "";
            _lTiled[i].Visible = false;                        
        }
        private void pbImage_MouseClick(object sender, MouseEventArgs e)
        {
            if (cbCoordinatesMouse.Checked)
            {
                int i = e.X / _width;
                int j = e.Y / _height;
                MessageBox.Show("hihi Array[" + j + "," + i + "] = "+ _arrmap[j,i]);                
            }
            if (_index == -1||_index==-2)
                return;
            int x = (e.X - pbImage.Location.X) / _width;
            int y = (e.Y - pbImage.Location.Y) / _height;         
            _lTiled[x + _column * y].Visible = true;
            _lTiled[x + _column * y].id = "" + _index;            
            panel1.Controls.Add(_lTiled[x + _column * y]);
            _lTiled[x + _column * y].BringToFront();                      
        }

        private void button2_Click(object sender, EventArgs e)
        {
            _index = -1;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            _index = -2;
        }
        private void btnGetObject_Click(object sender, EventArgs e) 
        {
            for (int i = 0; i < _lNameObject.Count; i++)
            {
                if (_lNameObject[i].Text == "")
                {
                    MessageBox.Show("Điền id cho các đối tượng!");
                    return;
                }
            }
            for (int i = 0; i < _lObject.Count; i++)
            {
                using (var stream = new FileStream(tbnoiluuim.Text + "\\" + _lNameObject[i].Text + ".txt", FileMode.Create, FileAccess.Write, FileShare.None))
                using (var writer = new StreamWriter(stream))
                {
                    int count = 0;
                    for (int j = _row - 1; j >= 0; j--)
                        for (int k = 0; k < _column; k++)
                            if (_lTiled[k + j * _column].id == _lObject[i].Name)
                                count++;
                    writer.WriteLine("" + count);
                    for (int j = _row - 1; j >= 0; j--)
                        for (int k = 0; k < _column; k++)
                        {
                            if (_lTiled[k + j * _column].id == _lObject[i].Name)
                            {
                                int x = k * _width;
                                int y = (_row - j) * _height;
                                writer.Write(x + " " + y + " ");
                            }
                        }
                    writer.Close();                    
                    
                }
            }
            MessageBox.Show("Đã Xong!");
        }
        private void pbImage_Paint(object sender, PaintEventArgs e)
        {
            Graphics g;
            g = e.Graphics;
            Pen p = new Pen(Color.Red, 0.5f);
            for (int i = 0; i <= _row; i++)
            {
                g.DrawLine(p, new Point(0, i * _height), new Point(_image.Width, i * _height));
            }
            for (int i = 0; i <= _column; i++)
            {
                g.DrawLine(p, new Point(i * _width, 0), new Point(i * _width, _image.Height));
            }
        }        
        private void panel1_MouseClick(object sender, MouseEventArgs e)
        {
            if(cbCoordinatesMouse.Checked)
            {
                int i = e.X / _width;
                int j = e.Y / _height;
                MessageBox.Show("hihi Array["+j+","+i+"] = "+_arrmap[j,i]);

            }
        }
        private void tbReplace_KeyPress(object sender, KeyPressEventArgs e)
        {
            e.Handled = !((e.KeyChar >= 48 && e.KeyChar <= 57) || e.KeyChar == 8);
        }

        private void tbReplaceWith_KeyPress(object sender, KeyPressEventArgs e)
        {
            e.Handled = !((e.KeyChar >= 48 && e.KeyChar <= 57) || e.KeyChar == 8);
        }

        private void btReplace_Click(object sender, EventArgs e)
        {
            if (tbReplaceWith.Text == "" || tbReplace.Text == "") { 
                MessageBox.Show("Vui lòng điền đầy đủ thông tin vào ô Replace và ô ReplaceWith");
                return;
            }
            int r = int.Parse(tbReplace.Text);
            int rw = int.Parse(tbReplaceWith.Text);
            for (int i = 0; i < _row; i++)
                for (int j = 0; j < _column; j++)
                    if (_arrmap[i, j] == r)
                        _arrmap[i, j] = rw;
            MessageBox.Show("Thay đổi Xong! Nếu ok click GetMaxtrix để lấy ma trận mới");
        }

        private void btChange_Matrix_Click(object sender, EventArgs e)
        {
            writemap(tbnoiluuim.Text + "\\" + tbIn.Text);
            MessageBox.Show("Đã ghi thành công! tới " + tbnoiluuim.Text + "/" + tbIn.Text+"để lấy file\n See You Again!");
        }                                
    }
}
