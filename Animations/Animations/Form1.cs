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
namespace Animations
{
    public partial class Form1 : Form
    {
        Bitmap output_Image;
        List<sprite> list_sprite=new List<sprite>();
        public Form1()
        {
            InitializeComponent();
            output_Image = new Bitmap(1024, 1024);
        }        
        private void tbSize_KeyPress(object sender, KeyPressEventArgs e)
        {
            e.Handled = !((e.KeyChar >= 48 && e.KeyChar <= 57) || e.KeyChar == 8);
        }

        string[] filenames = { };//chứa đường dẫn của file ảnh
        string[] filename = { };//chỉ chứa tên của file ảnh
        int max_width = 0, max_height = 0;//tìm ra hình chữ nhật bao quanh lớn nhất
        private void btOpentAllSprite_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFile = new OpenFileDialog();
            openFile.Filter = "Image|*.jpg;*.png;*.bmp;*.jpeg;*.gif";
            openFile.Multiselect = true;
            if (openFile.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                filenames = openFile.FileNames;
                filename = openFile.SafeFileNames;
            }
            for (int i = 0; i < filenames.Length; i++)
            { 
                Bitmap b = new Bitmap(filenames[i]);
                sprite s = new sprite();
                s.Image = b;
                max_width = max_width > b.Width ? max_width : b.Width;
                max_height = max_height > b.Height ? max_height : b.Height;
                if (b.Width % b.Height == 0)
                    s.c = b.Width / b.Height;
                else
                    s.c = b.Width / b.Height + 1;
                if (b.Width == 22 && b.Height == 18)
                    s.c = 1;
                if (b.Width == 64 && b.Height == 32)
                    s.c = 4;
                if (b.Width == 80 && b.Height == 32)
                    s.c = 4;
                if (b.Width == 48 && b.Height == 27)
                    s.c = 3;
                if (b.Width == 32 && b.Height == 32)
                    s.c = 2;
                if (b.Width == 16 && b.Height == 7)
                    s.c = 1;
                if (i == filename.Length - 1)
                    s.c = 1;
                Label l_information = new Label();
                l_information.Text = "" + s.c;
                s.Controls.Add(l_information);
                l_information.BringToFront();
                l_information.Location = new Point(0,0);
                l_information.BringToFront();
                l_information.Size = new Size(10, 10);
                l_information.BackColor = System.Drawing.Color.Cyan;
                l_information.ForeColor = Color.Red;
                p_mapImage.Controls.Add(s);

                s.Size = new Size(b.Width, b.Height);
                s.Location = new Point((i % 5)*192, (i / 5) * 48);//xét tọa độ x0, y0 bt: 192: 48
                s.BringToFront();
                s.MouseClick += new MouseEventHandler(sprite_click);
                list_sprite.Add(s);
                
            }

        }
        private void sprite_click(object sender, MouseEventArgs e)
        {
            sprite _s = (sprite)sender;
            MessageBox.Show("c= " + _s.c + " w=" + _s.Size.Width+ " h=" + _s.Size.Height);
        }

        private void getlistmario() //+list mushroom. dễ khai báo trong game
        {
            using (StreamWriter sw = new StreamWriter("Mario.txt"))
            { 
                for(int i=0;i<filename.Length;i++)
                {
                    if (filename[i].Contains("Mario") || filename[i].Contains("Bros"))
                    {
                        string[] s_name = filename[i].Split('.');
                        sw.WriteLine("FrkSprite* " + s_name[0]+";");
                    }
                }
                for (int i = 0; i < filename.Length; i++)
                {
                    if (filename[i].Contains("Tortoise"))
                    {
                        string[] s_name = filename[i].Split('.');
                        sw.WriteLine("FrkSprite* " + s_name[0]+";");
                    }
                }
                for (int i = 0; i < filename.Length; i++)
                {
                    if (filename[i].Contains("Mushroom"))
                    {
                        string[] s_name = filename[i].Split('.');
                        sw.WriteLine("FrkSprite* " + s_name[0] + ";");

                    }
                }
                for (int i = 0; i < filename.Length; i++)
                {
                    if (!filename[i].Contains("Tortoise") && !filename[i].Contains("Mushroom") && !filename[i].Contains("Mario") && !filename[i].Contains("Bros"))
                    {
                        string[] s_name = filename[i].Split('.');
                        sw.WriteLine("FrkSprite* " + s_name[0] + ";");
                    }
                }
                sw.Close();
            }
        }
        private void GetListMarioforLoad() 
        { 
             using (StreamWriter sw = new StreamWriter("Mario_Load.txt"))
            { 
                for(int i=0;i<filename.Length;i++)
                {
                    if (filename[i].Contains("Mario") || filename[i].Contains("Bros"))
                    {
                        string[] s_name = filename[i].Split('.');
                        sw.WriteLine(s_name[0] + "= ResourcesManager::GetInstance()->GetSprite(SpriteID::" + s_name[0]+ ");");
                    }
                }
                for (int i = 0; i < filename.Length; i++)
                {
                    if (filename[i].Contains("Tortoise"))
                    {
                        string[] s_name = filename[i].Split('.');
                        sw.WriteLine(s_name[0] + "= ResourcesManager::GetInstance()->GetSprite(SpriteID::" + s_name[0] + ");");
                    }
                }
                for (int i = 0; i < filename.Length; i++)
                {
                    if (filename[i].Contains("Mushroom"))
                    {
                        string[] s_name = filename[i].Split('.');
                        sw.WriteLine(s_name[0] + "= ResourcesManager::GetInstance()->GetSprite(SpriteID::" + s_name[0] + ");");
                    }
                }
                for (int i = 0; i < filename.Length; i++)
                {
                    if (!filename[i].Contains("Tortoise")&&!filename[i].Contains("Mushroom")&&!filename[i].Contains("Mario")&&!filename[i].Contains("Bros"))
                    {
                        string[] s_name = filename[i].Split('.');
                        sw.WriteLine(s_name[0] + "= ResourcesManager::GetInstance()->GetSprite(SpriteID::" + s_name[0] + ");");
                    }
                }
                sw.Close();
            }
        }
        private void btEnter_Click(object sender, EventArgs e)
        {
            p_mapImage.Size=new Size(1024,1024);
            using (StreamWriter sw = new StreamWriter("sprite.txt"))//lưu thông tin 
            {
                sw.Write(filenames.Length+"\r\n");
                for(int i = 0;i<filenames.Length;i++)
                {
                   // string[] tmp;
                    //tmp=filename[i].Split('.');
                    //sw.Write(tmp[0]+" ");
                    int w= list_sprite[i].Size.Width/list_sprite[i].c;
                    sw.Write(list_sprite[i].c + " " + list_sprite[i].Location.X + " " + list_sprite[i].Location.Y + " " + w + " " + list_sprite[i].Size.Height + "\r\n");
                }
                sw.WriteLine("Bye");
                sw.Close();
            }
            using (StreamWriter sw = new StreamWriter("listsprite.txt"))//lưu loại tên sprite
            {                
                for (int i = 0; i < filenames.Length; i++)
                {
                    string[] tmp;
                    tmp = filename[i].Split('.');
                    sw.Write(tmp[0] + ",");                    
                }                
                sw.Close();
            }
            foreach (sprite i in list_sprite)
            {
                using(Graphics g = Graphics.FromImage(output_Image))
                {
                    //g.DrawImage(i.Image, i.Location);
                    Rectangle rd = new Rectangle(i.Location, i.Size);
                    Rectangle rs = new Rectangle(0, 0, i.Size.Width, i.Size.Height);
                    g.DrawImage(i.Image, rd, rs, GraphicsUnit.Pixel);

                }
            }
            using (MemoryStream ms = new MemoryStream())
            {
                using (FileStream fs = new FileStream("Image.png", FileMode.Create, FileAccess.ReadWrite))
                {
                    output_Image.Save(ms, ImageFormat.Png);
                    byte[] bytes = ms.ToArray();
                    fs.Write(bytes, 0, bytes.Length);
                }
            }
            getlistmario();
            GetListMarioforLoad();
            MessageBox.Show("hihi");
        }

        
    }
}
