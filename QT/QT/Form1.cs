using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace QT
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {            
        }                
        private void pbImgMap_Paint(object sender, PaintEventArgs e)
        {
            if (pbImgMap.Image == null)
                return;
            Graphics g = e.Graphics;
            Pen p = new Pen(Color.DarkGreen, 0.1f);
            for (int i = 0; i <= pbImgMap.Image.Width / 16; i++)
            {
                int x = i * 16 ;
                g.DrawLine(p, new Point(x, 0), new Point(x, pbImgMap.Image.Height + 0));
            }
            for (int i = 0; i <= pbImgMap.Image.Height / 16; i++)
            {
                int y = i * 16 ;
                g.DrawLine(p, new Point(0, y), new Point(pbImgMap.Image.Width , y));
            }
            Pen q = new Pen(Color.Red,1.0f);
            for (int i = 0; i < 16; i++)
            {
                int x = i * 256;
                g.DrawLine(q, new Point(x, 0), new Point(x, 4096));
                g.DrawLine(q, new Point(0, x), new Point(4096, x));
            }
        }        
        private void btSrcMap_Click(object sender, EventArgs e)
        {
            OpenFileDialog op = new OpenFileDialog();
            op.Filter = "*.jpg|*.png";
            if (op.ShowDialog() == DialogResult.OK)
            {
                impMap = new Bitmap(op.FileName);
                pbImgMap.Image = impMap;
                colum_Count = impMap.Width / 16;
                row_Count = impMap.Height / 16;
                for (int i = 0; i < colum_Count * row_Count; i++)//dùng để kiểm tra đã có object tại vị trí vừa di chuyển qua hay chưa
                {
                    lCTreeObject.Add(new CTreeObject(new GameObject()));

                }
            }            
        }                 
        typeO ctype ;
        #region khai báo
        Bitmap impMap;
        int colum_Count;
        int row_Count;
        bool remove = false;
        int mousedown = 0;
        List<CTreeObject> lCTreeObject = new List<CTreeObject>();//dùng để kiểm tra 
        List<CTreeObject> lCtree = new List<CTreeObject>();

        List<CTreeObject> c_uprise = new List<CTreeObject>();
        List<CTreeObject> c_brick = new List<CTreeObject>();
        List<CTreeObject> c_music = new List<CTreeObject>();
        List<CTreeObject> c_land = new List<CTreeObject>();
        List<CTreeObject> c_tortoise = new List<CTreeObject>();
        List<CTreeObject> c_tortoise_fly = new List<CTreeObject>();
        List<CTreeObject> c_tortoise_red = new List<CTreeObject>();
        List<CTreeObject> c_mushroom_red = new List<CTreeObject>();
        List<CTreeObject> c_leaf = new List<CTreeObject>();
        List<CTreeObject> c_star = new List<CTreeObject>();
        List<CTreeObject> c_coin = new List<CTreeObject>();
        List<CTreeObject> c_question_block = new List<CTreeObject>();
        List<CTreeObject> c_tarnooki = new List<CTreeObject>();
        List<CTreeObject> c_tarnooki_fly = new List<CTreeObject>();
        List<CTreeObject> c_tree = new List<CTreeObject>();
        List<CTreeObject> c_tree_red = new List<CTreeObject>();
        List<CTreeObject> c_tree_shoot = new List<CTreeObject>();
        List<CTreeObject> c_tree_red_shoot = new List<CTreeObject>();
        List<CTreeObject> c_drain = new List<CTreeObject>();
        List<CTreeObject> c_p = new List<CTreeObject>();
        List<CTreeObject> c_box = new List<CTreeObject>();


        
        #endregion
        #region Click vào button chọn loại object
        private void btBox_Click(object sender, EventArgs e)
        {
            ctype = typeO.Box;
            pImageType.Image = Image.FromFile("box.png");
        }
        private void btMusic_Click(object sender, EventArgs e)
        {
            ctype = typeO.Music;
            pImageType.Image = Image.FromFile("music.png");
        }
        private void button1_Click(object sender, EventArgs e)
        {
            ctype = typeO.UpRise;
            pImageType.Image = Image.FromFile("hill.png");
        }
        private void btBrick_Click(object sender, EventArgs e)
        {
            ctype = typeO.brick;
            pImageType.Image = Image.FromFile("brick.png");
        }                
        PictureBox pImageType = new PictureBox();
        private void btReset_Click(object sender, EventArgs e)
        {
             ctype = typeO._null;
        }

        private void btTortoise_Click(object sender, EventArgs e)
        {
            ctype = typeO.tortoise;
            pImageType.Image = Image.FromFile("tortoise.png");
            pImageType.Size = new System.Drawing.Size(16, 16);            
            pbImgMap.Controls.Add(pImageType);
            //pImageType.BringToFront();
        }

        private void btLand_Click(object sender, EventArgs e)
        {
            ctype = typeO.land;
            pImageType.Image = Image.FromFile("land.png");
        }

        private void btTortoise_fly_Click(object sender, EventArgs e)
        {
            ctype = typeO.tortoise_fly;
            pImageType.Image = Image.FromFile("tortoise_fly.png");
        }
       

        private void btMushroom_red_Click(object sender, EventArgs e)
        {
            ctype = typeO.mushroom_red;
            pImageType.Image = Image.FromFile("mushroom_red.png");
        }

        private void btStar_Click(object sender, EventArgs e)
        {
            ctype = typeO.star;
            pImageType.Image = Image.FromFile("star.png");
        }

        private void bt_leaf_Click(object sender, EventArgs e)
        {
            ctype = typeO.leaf;
            pImageType.Image = Image.FromFile("leaf.png");
        }

        private void btQuestion_Block_Click(object sender, EventArgs e)
        {
            ctype = typeO.question_block;
            pImageType.Image = Image.FromFile("question_block.png");
        }

        private void btCoin_Click(object sender, EventArgs e)
        {
            ctype = typeO.coin;
            pImageType.Image = Image.FromFile("coin.png");
        }

        private void btTarnooki_Click(object sender, EventArgs e)
        {
            ctype = typeO.tarnooki;
            pImageType.Image = Image.FromFile("tarnooki.png");
        }

        private void btTarnooki_fly_Click(object sender, EventArgs e)
        {
            ctype = typeO.tarnooki_fly;
            pImageType.Image = Image.FromFile("tarnooki_fly.png");
        }

        private void btTree_Click(object sender, EventArgs e)
        {
            ctype = typeO.tree;
            pImageType.Image = Image.FromFile("tree.png");
            pImageType.Size = new Size(32, 32);
        }

        private void btTree_red_Click(object sender, EventArgs e)
        {
            ctype = typeO.tree_red;
            pImageType.Image = Image.FromFile("tree_red.png");
        }

        private void btDrain_Click(object sender, EventArgs e)
        {
            ctype = typeO.drain;
            pImageType.Image = Image.FromFile("drain.png");
        }
        private void btTortoise_red_Click(object sender, EventArgs e)
        {
            ctype = typeO.tortoise_red;
            pImageType.Image = Image.FromFile("tortoise_red.png");
        }

        private void btTree_Shoot_Click(object sender, EventArgs e)
        {
            ctype = typeO.tree_shoot;
            pImageType.Image = Image.FromFile("tree_shoot.png");
        }
        private void btTree_Red_Shoot_Click(object sender, EventArgs e)
        {
            ctype = typeO.tree_red_shoot;
            pImageType.Image = Image.FromFile("tree_red_shoot.png");
        }
        private void btP_Click(object sender, EventArgs e)
        {
            ctype = typeO.p;
            pImageType.Image = Image.FromFile("p.png");
        }
        #endregion        
        #region Sự kiện của Picture Box
        CTreeObject Land;

        private void pbImgMap_MouseDown(object sender, MouseEventArgs e)
        {
            mousedown = 1;
            if (set) {
                MessageBox.Show("mouse.X = " + e.X + " mouse.Y = " + e.Y);
                return;
            }            
            if (ctype == typeO._null || remove)
                return;
            int i = e.X / 16;
            int j = e.Y / 16;
            int index = j * colum_Count + i;
            if (index < 0 || index >= row_Count * colum_Count)//Kiểm tra phần tử có chỉ số index có tồn tại hay không
                return;
            //Thêm đối tượng vào map            
            //if (lCTreeObject[index].id == -1)//Kiểm tra tại vị trí đang xét đã có hay chưa, có rồi thì thôi
            //{
                lCTreeObject[index].id = index;
                lCTreeObject[index].gameObject.id = index;
            //}
            //else
                //return;
            GameObject t = new GameObject(index, ctype);
            t.Image = pImageType.Image;
            t.Size = new System.Drawing.Size(t.Image.Width, t.Image.Height);
            t.Location = new Point(i * 16, j * 16);
            Rectangle r = new Rectangle(i * 16, j * 16, t.Image.Width, t.Image.Height);
            CTreeObject ct = new CTreeObject(index, r, t);
            ct.gameObject.MouseDown += new MouseEventHandler(cTreeObject_MouseDown);            

            switch (ctype)
            {
                case typeO.UpRise:
                    c_uprise.Add(ct);                    
                    lCtree.Add(c_uprise[c_uprise.Count - 1]);
                    break;
                case typeO.brick:
                    c_brick.Add(ct);
                    pbImgMap.Controls.Add(c_brick[c_brick.Count - 1].gameObject);
                    c_brick[c_brick.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_brick[c_brick.Count - 1]);
                    break;
                case typeO.Music:
                    c_music.Add(ct);
                    pbImgMap.Controls.Add(c_music[c_music.Count - 1].gameObject);
                    c_music[c_music.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_music[c_music.Count - 1]);
                    break;

                case typeO.coin:
                    c_coin.Add(ct);
                    pbImgMap.Controls.Add(c_coin[c_coin.Count - 1].gameObject);
                    c_coin[c_coin.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_coin[c_coin.Count - 1]);
                    break;
                case typeO.drain:
                    c_drain.Add(ct);
                    pbImgMap.Controls.Add(c_drain[c_drain.Count - 1].gameObject);
                    c_drain[c_drain.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_drain[c_drain.Count - 1]);
                    break;
                case typeO.land:
                    c_land.Add(ct);
                    pbImgMap.Controls.Add(c_land[c_land.Count - 1].gameObject);
                    c_land[c_land.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_land[c_land.Count - 1]);
                    break;
                    case typeO.tree_shoot:
                    c_tree_shoot.Add(ct);
                    pbImgMap.Controls.Add(c_tree_shoot[c_tree_shoot.Count - 1].gameObject);
                    c_tree_shoot[c_tree_shoot.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_tree_shoot[c_tree_shoot.Count - 1]);
                    break;
                case typeO.leaf:
                    c_leaf.Add(ct);
                    pbImgMap.Controls.Add(c_leaf[c_leaf.Count - 1].gameObject);
                    c_leaf[c_leaf.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_leaf[c_leaf.Count - 1]);
                    break;
                case typeO.mushroom_red:
                    c_mushroom_red.Add(ct);
                    pbImgMap.Controls.Add(c_mushroom_red[c_mushroom_red.Count - 1].gameObject);
                    c_mushroom_red[c_mushroom_red.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_mushroom_red[c_mushroom_red.Count - 1]);
                    break;
                case typeO.p:
                    c_p.Add(ct);
                    pbImgMap.Controls.Add(c_p[c_p.Count - 1].gameObject);
                    c_p[c_p.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_p[c_p.Count - 1]);
                    break;
                case typeO.Box:
                    c_box.Add(ct);
                    pbImgMap.Controls.Add(c_box[c_box.Count - 1].gameObject);
                    c_box[c_box.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_box[c_box.Count - 1]);
                    break;
                case typeO.question_block:
                    c_question_block.Add(ct);
                    pbImgMap.Controls.Add(c_question_block[c_question_block.Count - 1].gameObject);
                    c_question_block[c_question_block.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_question_block[c_question_block.Count - 1]);
                    break;
                case typeO.star:
                    c_star.Add(ct);
                    pbImgMap.Controls.Add(c_star[c_star.Count - 1].gameObject);
                    c_star[c_star.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_star[c_star.Count - 1]);
                    break;
                case typeO.tarnooki:
                    c_tarnooki.Add(ct);
                    pbImgMap.Controls.Add(c_tarnooki[c_tarnooki.Count - 1].gameObject);
                    c_tarnooki[c_tarnooki.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_tarnooki[c_tarnooki.Count - 1]);
                    break;
                case typeO.tarnooki_fly:
                    c_tarnooki_fly.Add(ct);
                    pbImgMap.Controls.Add(c_tarnooki_fly[c_tarnooki_fly.Count - 1].gameObject);
                    c_tarnooki_fly[c_tarnooki_fly.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_tarnooki_fly[c_tarnooki_fly.Count - 1]);
                    break;
                case typeO.tortoise:
                    c_tortoise.Add(ct);
                    pbImgMap.Controls.Add(c_tortoise[c_tortoise.Count - 1].gameObject);
                    c_tortoise[c_tortoise.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_tortoise[c_tortoise.Count - 1]);
                    break;
                case typeO.tortoise_fly:
                    c_tortoise_fly.Add(ct);
                    pbImgMap.Controls.Add(c_tortoise_fly[c_tortoise_fly.Count - 1].gameObject);
                    c_tortoise_fly[c_tortoise_fly.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_tortoise_fly[c_tortoise_fly.Count - 1]);
                    break;
                case typeO.tortoise_red:
                    c_tortoise_red.Add(ct);
                    pbImgMap.Controls.Add(c_tortoise_red[c_tortoise_red.Count - 1].gameObject);
                    c_tortoise_red[c_tortoise_red.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_tortoise_red[c_tortoise_red.Count - 1]);
                    break;
                case typeO.tree:
                    c_tree.Add(ct);
                    pbImgMap.Controls.Add(c_tree[c_tree.Count - 1].gameObject);
                    c_tree[c_tree.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_tree[c_tree.Count - 1]);
                    break;
                case typeO.tree_red:
                    c_tree_red.Add(ct);
                    pbImgMap.Controls.Add(c_tree_red[c_tree_red.Count - 1].gameObject);
                    c_tree_red[c_tree_red.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_tree_red[c_tree_red.Count - 1]);
                    break;
                case typeO.tree_red_shoot:
                    c_tree_red_shoot.Add(ct);
                    pbImgMap.Controls.Add(c_tree_red_shoot[c_tree_red_shoot.Count - 1].gameObject);
                    c_tree_red_shoot[c_tree_red_shoot.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_tree_red_shoot[c_tree_red_shoot.Count - 1]);
                    break;
                

            }
        }        
        private void pbImgMap_MouseMove(object sender, MouseEventArgs e)
        {
            if (ctype == typeO._null || mousedown == 0 || remove)
                return;
            int i = e.X / 16;
            int j = e.Y / 16;
            int index = j * colum_Count + i;
            if (index < 0 || index > row_Count * colum_Count)//Kiểm tra phần tử có chỉ số index có tồn tại hay không
                return;
            //Thêm đối tượng vào map            
            if (lCTreeObject[index].id == -1)//Kiểm tra tại vị trí đang xét đã có hay chưa, có rồi thì thôi
            {
                lCTreeObject[index].id = index;
                lCTreeObject[index].gameObject.id = index;
            }
            else
                return;
            GameObject t = new GameObject(index, ctype);
            t.Image = pImageType.Image;
            t.Size = new System.Drawing.Size(t.Image.Width, t.Image.Height);
            t.Location = new Point(i * 16, j * 16);
            Rectangle r = new Rectangle(i * 16, j * 16, t.Image.Width, t.Image.Height);
            CTreeObject ct = new CTreeObject(index, r, t);
            ct.gameObject.MouseDown += new MouseEventHandler(cTreeObject_MouseDown);

            switch (ctype)
            {
                case typeO.brick:
                    c_brick.Add(ct);
                    pbImgMap.Controls.Add(c_brick[c_brick.Count - 1].gameObject);
                    c_brick[c_brick.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_brick[c_brick.Count - 1]);
                    break;
                case typeO.Music:
                    c_music.Add(ct);
                    pbImgMap.Controls.Add(c_music[c_music.Count - 1].gameObject);
                    c_music[c_music.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_music[c_music.Count - 1]);
                    break;
                case typeO.coin:
                    c_coin.Add(ct);
                    pbImgMap.Controls.Add(c_coin[c_coin.Count - 1].gameObject);
                    c_coin[c_coin.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_coin[c_coin.Count - 1]);
                    break;
                case typeO.drain:
                    c_drain.Add(ct);
                    pbImgMap.Controls.Add(c_drain[c_drain.Count - 1].gameObject);
                    c_drain[c_drain.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_drain[c_drain.Count - 1]);
                    break;
                /*case typeO.land:
                    c_land.Add(ct);
                    pbImgMap.Controls.Add(c_land[c_land.Count - 1].gameObject);
                    c_land[c_land.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_land[c_land.Count - 1]);
                    break;*/
                case typeO.leaf:
                    c_leaf.Add(ct);
                    pbImgMap.Controls.Add(c_leaf[c_leaf.Count - 1].gameObject);
                    c_leaf[c_leaf.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_leaf[c_leaf.Count - 1]);
                    break;
                case typeO.mushroom_red:
                    c_mushroom_red.Add(ct);
                    pbImgMap.Controls.Add(c_mushroom_red[c_mushroom_red.Count - 1].gameObject);
                    c_mushroom_red[c_mushroom_red.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_mushroom_red[c_mushroom_red.Count - 1]);
                    break;
                case typeO.p:
                    c_p.Add(ct);
                    pbImgMap.Controls.Add(c_p[c_p.Count - 1].gameObject);
                    c_p[c_p.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_p[c_p.Count - 1]);
                    break;
                /*case typeO.Box:
                    c_box.Add(ct);
                    pbImgMap.Controls.Add(c_box[c_box.Count - 1].gameObject);
                    c_box[c_box.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_box[c_box.Count - 1]);
                    break;*/
                case typeO.question_block:
                    c_question_block.Add(ct);
                    pbImgMap.Controls.Add(c_question_block[c_question_block.Count - 1].gameObject);
                    c_question_block[c_question_block.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_question_block[c_question_block.Count - 1]);
                    break;
                case typeO.star:
                    c_star.Add(ct);
                    pbImgMap.Controls.Add(c_star[c_star.Count - 1].gameObject);
                    c_star[c_star.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_star[c_star.Count - 1]);
                    break;
                case typeO.tarnooki:
                    c_tarnooki.Add(ct);
                    pbImgMap.Controls.Add(c_tarnooki[c_tarnooki.Count - 1].gameObject);
                    c_tarnooki[c_tarnooki.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_tarnooki[c_tarnooki.Count - 1]);
                    break;
                case typeO.tarnooki_fly:
                    c_tarnooki_fly.Add(ct);
                    pbImgMap.Controls.Add(c_tarnooki_fly[c_tarnooki_fly.Count - 1].gameObject);
                    c_tarnooki_fly[c_tarnooki_fly.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_tarnooki_fly[c_tarnooki_fly.Count - 1]);
                    break;
                case typeO.tortoise:
                    c_tortoise.Add(ct);
                    pbImgMap.Controls.Add(c_tortoise[c_tortoise.Count - 1].gameObject);
                    c_tortoise[c_tortoise.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_tortoise[c_tortoise.Count - 1]);
                    break;
                case typeO.tortoise_fly:
                    c_tortoise_fly.Add(ct);
                    pbImgMap.Controls.Add(c_tortoise_fly[c_tortoise_fly.Count - 1].gameObject);
                    c_tortoise_fly[c_tortoise_fly.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_tortoise_fly[c_tortoise_fly.Count - 1]);
                    break;
                case typeO.tortoise_red:
                    c_tortoise_red.Add(ct);
                    pbImgMap.Controls.Add(c_tortoise_red[c_tortoise_red.Count - 1].gameObject);
                    c_tortoise_red[c_tortoise_red.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_tortoise_red[c_tortoise_red.Count - 1]);
                    break;
                case typeO.tree:
                    c_tree.Add(ct);
                    pbImgMap.Controls.Add(c_tree[c_tree.Count - 1].gameObject);
                    c_tree[c_tree.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_tree[c_tree.Count - 1]);
                    break;
                case typeO.tree_red:
                    c_tree_red.Add(ct);
                    pbImgMap.Controls.Add(c_tree_red[c_tree_red.Count - 1].gameObject);
                    c_tree_red[c_tree_red.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_tree_red[c_tree_red.Count - 1]);
                    break;
                case typeO.tree_red_shoot:
                    c_tree_red_shoot.Add(ct);
                    pbImgMap.Controls.Add(c_tree_red_shoot[c_tree_red_shoot.Count - 1].gameObject);
                    c_tree_red_shoot[c_tree_red_shoot.Count - 1].gameObject.BringToFront();
                    lCtree.Add(c_tree_red_shoot[c_tree_red_shoot.Count - 1]);
                    break;
                //case typeO.tree_shoot:
                //    c_tree_shoot.Add(ct);
                //    pbImgMap.Controls.Add(c_tree_shoot[c_tree_shoot.Count - 1].gameObject);
                //    c_tree_shoot[c_tree_shoot.Count - 1].gameObject.BringToFront();
                //    lCtree.Add(c_tree_shoot[c_tree_shoot.Count - 1]);
                //    break;

            }
        }

        private void pbImgMap_MouseUp(object sender, MouseEventArgs e)
        {
            if (mousedown != 1)
                return;
            if (ctype == typeO.land) 
            {
                int i = e.X / 16;
                int j = e.Y / 16;                
                int i0 = c_land[c_land.Count - 1].oRect.X / 16;
                int j0 = c_land[c_land.Count - 1].oRect.Y / 16;                
                c_land[c_land.Count - 1].oRect.Width = (Math.Abs(i - i0) + 1) * 16;
                c_land[c_land.Count - 1].oRect.Height= (Math.Abs(j - j0) + 1) * 16;
                c_land[c_land.Count - 1].gameObject.Size = new Size(c_land[c_land.Count - 1].oRect.Width, c_land[c_land.Count - 1].oRect.Height);
                c_land[c_land.Count - 1].gameObject.BackColor = Color.Cyan;
            }
            if (ctype == typeO.tree_shoot)
            {
                int i = e.X / 16;
                int j = e.Y / 16;
                int i0 = c_tree_shoot[c_tree_shoot.Count - 1].oRect.X / 16;
                int j0 = c_tree_shoot[c_tree_shoot.Count - 1].oRect.Y / 16;
                c_tree_shoot[c_tree_shoot.Count - 1].oRect.Width = (Math.Abs(i - i0) + 1) * 16;
                c_tree_shoot[c_tree_shoot.Count - 1].oRect.Height = (Math.Abs(j - j0) + 1) * 16;
                c_tree_shoot[c_tree_shoot.Count - 1].gameObject.Size = new Size(c_tree_shoot[c_tree_shoot.Count - 1].oRect.Width, c_tree_shoot[c_tree_shoot.Count - 1].oRect.Height);
                c_tree_shoot[c_tree_shoot.Count - 1].gameObject.BackColor = Color.Cyan;
            }
            if (ctype == typeO.Box)
            {
                int i = e.X / 16;
                int j = e.Y / 16;
                int i0 = c_box[c_box.Count - 1].oRect.X / 16;
                int j0 = c_box[c_box.Count - 1].oRect.Y / 16;
                c_box[c_box.Count - 1].oRect.Width = (i - i0 + 1) * 16;
                c_box[c_box.Count - 1].oRect.Height = (j - j0 + 1) * 16;
                c_box[c_box.Count - 1].gameObject.Size = new Size(c_box[c_box.Count - 1].oRect.Width, c_box[c_box.Count - 1].oRect.Height);
                c_box[c_box.Count - 1].gameObject.BackColor = Color.DeepPink;
            }
            if (ctype == typeO.UpRise) 
            {
                int i = e.X / 16;
                int j = e.Y / 16;
                int i0 = c_uprise[c_uprise.Count - 1].oRect.X / 16;
                int j0 = c_uprise[c_uprise.Count - 1].oRect.Y / 16;
                if (j0 >= j)
                {
                    c_uprise[c_uprise.Count - 1].oRect.Y = j * 16;
                    c_uprise[c_uprise.Count - 1].gameObject.Location = new Point(i0*16, j * 16);
                    c_uprise[c_uprise.Count - 1].IsUprise = 1;
                    c_uprise[c_uprise.Count - 1].gameObject.vy = -j + j0 + 1;
                }
                else
                {
                    c_uprise[c_uprise.Count - 1].gameObject.vy = -j + j0 - 1;
                }
                c_uprise[c_uprise.Count - 1].gameObject.vx = i - i0+1;                
                c_uprise[c_uprise.Count - 1].oRect.Width = (Math.Abs(i - i0) + 1) * 16;
                c_uprise[c_uprise.Count - 1].oRect.Height = (Math.Abs(j - j0) + 1) * 16;
                c_uprise[c_uprise.Count - 1].gameObject.Size = new Size(c_uprise[c_uprise.Count - 1].oRect.Width, c_uprise[c_uprise.Count - 1].oRect.Height);

                c_uprise[c_uprise.Count - 1].gameObject.BackColor = Color.Cyan;
                pbImgMap.Controls.Add(c_uprise[c_uprise.Count - 1].gameObject);
                c_uprise[c_uprise.Count - 1].gameObject.BringToFront();
                c_uprise[c_uprise.Count - 1].gameObject.Paint += new System.Windows.Forms.PaintEventHandler(this.pbUprise_Paint);
            }
            mousedown = 0;            
        }
        private void pbUprise_Paint(object sender, PaintEventArgs e) 
        {
            GameObject t = (GameObject)sender;
            Graphics g = e.Graphics;
            Pen p = new Pen(Color.DarkGreen, 0.5f);
            if (t.vy < 0)
            {
                g.DrawLine(p, new Point(0, 0), new Point(t.Width, t.Height));
            }
            else
            {
                g.DrawLine(p, new Point(0, t.Height), new Point(t.Width, 0));
            }
            
        }        
        #endregion              
        bool check_setregion() {
            int x1, y1, x2, y2;
            try
            {
                x1 = int.Parse(tbx1.Text);
                y1 = int.Parse(tby1.Text);
                x2 = int.Parse(tbx2.Text);
                y2 = int.Parse(tby2.Text);
            }
            catch {
                MessageBox.Show("Kiểm tra lại vùng di chuyển");
                return false;
            }
            if(x1>=x2||y1>=y2)
            {
                MessageBox.Show("Kiểm tra lại vùng di chuyển");
                return false;
            }

            return true;
        }
        private void cTreeObject_MouseDown(object sender, MouseEventArgs e)
        {
            if (set&&check_setregion()) {
                int x1, y1, x2, y2, w, h;
                x1 = int.Parse(tbx1.Text);
                y1 = int.Parse(tby1.Text);
                x2 = int.Parse(tbx2.Text);
                y2 = int.Parse(tby2.Text);
                w = x2 - x1;
                h = y2 - y1;
                GameObject g = (GameObject)sender;
                for (int l = 0; l < lCtree.Count; l++)
                {
                    if (lCtree[l].id == g.id)
                    {                        
                        lCtree[l].oRect = new Rectangle(x1, y1, w, h);
                        MessageBox.Show("Ok, đã cập nhật vùng di chuyển ");
                        break;
                    }
                }
                return;
            }
            if (!remove)
                return;
            GameObject ct = (GameObject)sender;
            int i = ct.Location.X / 16;
            int j = ct.Location.Y / 16;
            int index = j * colum_Count + i;
            //if (index < 0 || index > row_Count * colum_Count)//Kiểm tra phần tử có chỉ số index có tồn tại hay không
              //  return;
            //if (lCTreeObject[index].id == -1)
              //  return;
            for(int l=0;l<lCtree.Count;l++) {
                if (lCtree[l].id == ct.id)
                {
                    lCtree.RemoveAt(l);
                    break;
                }
            }
            switch (ct.type) 
            {
                case typeO.UpRise:
                    for (int u = 0; u < c_uprise.Count; u++)
                    {
                        if (c_uprise[u].id == ct.id)
                        {
                            lCTreeObject[index].id = -1;
                            pbImgMap.Controls.Remove(c_uprise[u].gameObject);
                            c_uprise.RemoveAt(u);
                        }
                    }
                    break;
                case typeO.brick:
                    for (int u = 0; u< c_brick.Count;u++ )
                    {
                        if(c_brick[u].id==ct.id)
                        {                            
                            lCTreeObject[index].id = -1;
                            pbImgMap.Controls.Remove(c_brick[u].gameObject);
                            c_brick.RemoveAt(u);
                        }
                    }
                        break;
                case typeO.Music:
                        for (int u = 0; u < c_music.Count; u++)
                        {
                            if (c_music[u].id == ct.id)
                            {
                                lCTreeObject[index].id = -1;
                                pbImgMap.Controls.Remove(c_music[u].gameObject);
                                c_music.RemoveAt(u);
                            }
                        }
                        break;
                case typeO.coin:
                        for (int u = 0; u < c_coin.Count; u++)
                        {
                            if (c_coin[u].id == ct.id)
                            {
                                lCTreeObject[index].id = -1;
                                pbImgMap.Controls.Remove(c_coin[u].gameObject);
                                c_coin.RemoveAt(u);
                            }
                        }
                    break;
                case typeO.drain:
                    for (int u = 0; u < c_drain.Count; u++)
                    {
                        if (c_drain[u].id == ct.id)
                        {
                            lCTreeObject[index].id = -1;
                            pbImgMap.Controls.Remove(c_drain[u].gameObject);
                            c_drain.RemoveAt(u);
                        }
                    }
                    break;
                case typeO.land:
                    for (int u = 0; u < c_land.Count; u++)
                    {
                        if (c_land[u].id == ct.id)
                        {
                            lCTreeObject[index].id = -1;
                            pbImgMap.Controls.Remove(c_land[u].gameObject);
                            c_land.RemoveAt(u);
                        }
                    }
                    break;
                case typeO.leaf:
                    for (int u = 0; u < c_leaf.Count; u++)
                    {
                        if (c_leaf[u].id == ct.id)
                        {
                            lCTreeObject[index].id = -1;
                            pbImgMap.Controls.Remove(c_leaf[u].gameObject);
                            c_leaf.RemoveAt(u);
                        }
                    }
                    break;
                case typeO.mushroom_red:
                    for (int u = 0; u < c_mushroom_red.Count; u++)
                    {
                        if (c_mushroom_red[u].id == ct.id)
                        {
                            lCTreeObject[index].id = -1;
                            pbImgMap.Controls.Remove(c_mushroom_red[u].gameObject);
                            c_mushroom_red.RemoveAt(u);
                        }
                    }
                    break;
                case typeO.p:
                    for (int u = 0; u < c_p.Count; u++)
                    {
                        if (c_p[u].id == ct.id)
                        {
                            lCTreeObject[index].id = -1;
                            pbImgMap.Controls.Remove(c_p[u].gameObject);
                            c_p.RemoveAt(u);
                        }
                    }
                    break;
                case typeO.Box:
                    for (int u = 0; u < c_box.Count; u++)
                    {
                        if (c_box[u].id == ct.id)
                        {
                            lCTreeObject[index].id = -1;
                            pbImgMap.Controls.Remove(c_box[u].gameObject);
                            c_box.RemoveAt(u);
                        }
                    }
                    break;
                case typeO.question_block:
                    for (int u = 0; u < c_question_block.Count; u++)
                    {
                        if (c_question_block[u].id == ct.id)
                        {
                            lCTreeObject[index].id = -1;
                            pbImgMap.Controls.Remove(c_question_block[u].gameObject);
                            c_question_block.RemoveAt(u);
                        }
                    }
                    break;
                case typeO.star:
                    for (int u = 0; u < c_star.Count; u++)
                    {
                        if (c_star[u].id == ct.id)
                        {
                            lCTreeObject[index].id = -1;
                            pbImgMap.Controls.Remove(c_star[u].gameObject);
                            c_star.RemoveAt(u);
                        }
                    }
                    break;
                case typeO.tarnooki:
                    for (int u = 0; u < c_tarnooki.Count; u++)
                    {
                        if (c_tarnooki[u].id == ct.id)
                        {
                            lCTreeObject[index].id = -1;
                            pbImgMap.Controls.Remove(c_tarnooki[u].gameObject);
                            c_tarnooki.RemoveAt(u);
                        }
                    }
                    break;
                case typeO.tarnooki_fly:
                    for (int u = 0; u < c_tarnooki_fly.Count; u++)
                    {
                        if (c_tarnooki_fly[u].id == ct.id)
                        {
                            lCTreeObject[index].id = -1;
                            pbImgMap.Controls.Remove(c_tarnooki_fly[u].gameObject);
                            c_tarnooki_fly.RemoveAt(u);
                        }
                    }
                    break;
                case typeO.tortoise:
                    for (int u = 0; u < c_tortoise.Count; u++)
                    {
                        if (c_tortoise[u].id == ct.id)
                        {
                            lCTreeObject[index].id = -1;
                            pbImgMap.Controls.Remove(c_tortoise[u].gameObject);
                            c_tortoise.RemoveAt(u);
                        }
                    }
                    break;
                case typeO.tortoise_fly:
                    for (int u = 0; u < c_tortoise_fly.Count; u++)
                    {
                        if (c_tortoise_fly[u].id == ct.id)
                        {
                            lCTreeObject[index].id = -1;
                            pbImgMap.Controls.Remove(c_tortoise_fly[u].gameObject);
                            c_tortoise_fly.RemoveAt(u);
                        }
                    }
                    break;
                case typeO.tortoise_red:
                    for (int u = 0; u < c_tortoise_red.Count; u++)
                    {
                        if (c_tortoise_red[u].id == ct.id)
                        {
                            lCTreeObject[index].id = -1;
                            pbImgMap.Controls.Remove(c_tortoise_red[u].gameObject);
                            c_tortoise_red.RemoveAt(u);
                        }
                    }
                    break;
                case typeO.tree:
                    for (int u = 0; u < c_tree.Count; u++)
                    {
                        if (c_tree[u].id == ct.id)
                        {
                            lCTreeObject[index].id = -1;
                            pbImgMap.Controls.Remove(c_tree[u].gameObject);
                            c_tree.RemoveAt(u);
                        }
                    }
                    break;
                case typeO.tree_red:
                    for (int u = 0; u < c_tree_red.Count; u++)
                    {
                        if (c_tree_red[u].id == ct.id)
                        {
                            lCTreeObject[index].id = -1;
                            pbImgMap.Controls.Remove(c_tree_red[u].gameObject);
                            c_tree_red.RemoveAt(u);
                        }
                    }
                    break;
                case typeO.tree_red_shoot:
                    for (int u = 0; u < c_tree_red_shoot.Count; u++)
                    {
                        if (c_tree_red_shoot[u].id == ct.id)
                        {
                            lCTreeObject[index].id = -1;
                            pbImgMap.Controls.Remove(c_tree_red_shoot[u].gameObject);
                            c_tree_red_shoot.RemoveAt(u);
                        }
                    }
                    break;
                case typeO.tree_shoot:
                    for (int u = 0; u < c_tree_shoot.Count; u++)
                    {
                        if (c_tree_shoot[u].id == ct.id)
                        {
                            lCTreeObject[index].id = -1;
                            pbImgMap.Controls.Remove(c_tree_shoot[u].gameObject);
                            c_tree_shoot.RemoveAt(u);
                        }
                    }
                    break;                                                                    
            }
        }
              
        private void btCheckOut_Click(object sender, EventArgs e)
        {
            QNode n = new QNode(0, new Rectangle(0, 0, 4096, 4096));
            foreach (CTreeObject i in lCtree)
                n.Insert(i);
            n.nodela();
            n.ghifile();
            n.getListQNode();
            n.Writer_QNode();
            Write_Object();
            MessageBox.Show("Hi hihi");
        }

        private void btRemove_Click(object sender, EventArgs e)
        {
            remove = !remove;
            if (remove == true)//tắt bắt sự kiện của pbImgMap
            {

                btRemove.Text = "Remove: on";
                pbImgMap.MouseDown -= new MouseEventHandler(pbImgMap_MouseDown);
                pbImgMap.MouseUp -= new MouseEventHandler(pbImgMap_MouseUp);
                pbImgMap.MouseMove -= new MouseEventHandler(pbImgMap_MouseMove);                

            }
            else{
                btRemove.Text = "Remove: off";
                pbImgMap.MouseDown += new MouseEventHandler(pbImgMap_MouseDown);
                pbImgMap.MouseUp += new MouseEventHandler(pbImgMap_MouseUp);
                pbImgMap.MouseMove += new MouseEventHandler(pbImgMap_MouseMove);
            }
        }
        private void Write_Object()
        {
            int mapHeight = pbImgMap.Height;
            using (StreamWriter sw = new StreamWriter("C:/Users/HomeSK/Desktop/Mario-Bros-3.git/trunk/NMPTG/Object2.txt"))
            {
                sw.WriteLine("brick" + " " + c_brick.Count);
                for (int i = 0; i < c_brick.Count; i++)
                {
                    sw.WriteLine(c_brick[i].id + " " + c_brick[i].oRect.X + " " + (mapHeight - c_brick[i].oRect.Bottom) + " " + c_brick[i].oRect.Width+" "+c_brick[i].oRect.Height);
                }
                sw.WriteLine("coin" + " " + c_coin.Count);
                for (int i = 0; i < c_coin.Count; i++)
                {
                    sw.WriteLine(c_coin[i].id + " " + c_coin[i].oRect.X + " " + (mapHeight - c_coin[i].oRect.Bottom) + " " + c_coin[i].oRect.Width + " " + c_coin[i].oRect.Height);
                }
                sw.WriteLine("drain" + " " + c_drain.Count);
                for (int i = 0; i < c_drain.Count; i++)
                {
                    sw.WriteLine(c_drain[i].id + " " + c_drain[i].oRect.X + " " + (mapHeight - c_drain[i].oRect.Bottom) + " " + c_drain[i].oRect.Width + " " + c_drain[i].oRect.Height);
                }
                sw.WriteLine("land" + " " + c_land.Count);
                for (int i = 0; i < c_land.Count; i++)
                {
                    sw.WriteLine(c_land[i].id + " " + c_land[i].oRect.X + " " + (mapHeight - c_land[i].oRect.Bottom) + " " + c_land[i].oRect.Width + " " + c_land[i].oRect.Height);
                }
                sw.WriteLine("leaf" + " " + c_leaf.Count);
                for (int i = 0; i < c_leaf.Count; i++)
                {
                    sw.WriteLine(c_leaf[i].id + " " + c_leaf[i].oRect.X + " " + (mapHeight - c_leaf[i].oRect.Bottom) + " " + c_leaf[i].oRect.Width + " " + c_leaf[i].oRect.Height);
                }
                sw.WriteLine("mushroom_red" + " " + c_mushroom_red.Count);
                for (int i = 0; i < c_mushroom_red.Count; i++)
                {
                    sw.WriteLine(c_mushroom_red[i].id + " " + c_mushroom_red[i].oRect.X + " " + (mapHeight - c_mushroom_red[i].oRect.Bottom) + " " + c_mushroom_red[i].oRect.Width + " " + c_mushroom_red[i].oRect.Height);
                }
                sw.WriteLine("p" + " " + c_p.Count);
                for (int i = 0; i < c_p.Count; i++)
                {
                    sw.WriteLine(c_p[i].id + " " + c_p[i].oRect.X + " " + (mapHeight - c_p[i].oRect.Bottom) + " " + c_p[i].oRect.Width + " " + c_p[i].oRect.Height);
                }
                sw.WriteLine("box" + " " + c_box.Count);
                for (int i = 0; i < c_box.Count; i++)
                {
                    sw.WriteLine(c_box[i].id + " " + c_box[i].oRect.X + " " + (mapHeight - c_box[i].oRect.Bottom) + " " + c_box[i].oRect.Width + " " + c_box[i].oRect.Height);
                }
                sw.WriteLine("question_block" + " " + c_question_block.Count);
                for (int i = 0; i < c_question_block.Count; i++)
                {
                    sw.WriteLine(c_question_block[i].id + " " + c_question_block[i].oRect.X + " " + (mapHeight - c_question_block[i].oRect.Bottom) + " " + c_question_block[i].oRect.Width + " " + c_question_block[i].oRect.Height);
                }
                sw.WriteLine("star" + " " + c_star.Count);
                for (int i = 0; i < c_star.Count; i++)
                {
                    sw.WriteLine(c_star[i].id + " " + c_star[i].oRect.X + " " + (mapHeight - c_star[i].oRect.Bottom) + " " + c_star[i].oRect.Width + " " + c_star[i].oRect.Height);
                }
                sw.WriteLine("tarnooki" + " " + c_tarnooki.Count);
                for (int i = 0; i < c_tarnooki.Count; i++)
                {
                    sw.WriteLine(c_tarnooki[i].id + " " + c_tarnooki[i].oRect.X + " " + (mapHeight - c_tarnooki[i].oRect.Bottom) + " " + c_tarnooki[i].oRect.Width + " " + c_tarnooki[i].oRect.Height);
                }
                sw.WriteLine("tarnooki_fly" + " " + c_tarnooki_fly.Count);
                for (int i = 0; i < c_tarnooki_fly.Count; i++)
                {
                    sw.WriteLine(c_tarnooki_fly[i].id + " " + c_tarnooki_fly[i].oRect.X + " " + (mapHeight - c_tarnooki_fly[i].oRect.Bottom) + " " + c_tarnooki_fly[i].oRect.Width + " " + c_tarnooki_fly[i].oRect.Height);
                }
                sw.WriteLine("tortoise" + " " + c_tortoise.Count);
                for (int i = 0; i < c_tortoise.Count; i++)
                {
                    sw.WriteLine(c_tortoise[i].id + " " + c_tortoise[i].oRect.X + " " + (mapHeight - c_tortoise[i].oRect.Bottom) + " " + c_tortoise[i].oRect.Width + " " + c_tortoise[i].oRect.Height);
                }
                sw.WriteLine("tortoise_fly" + " " + c_tortoise_fly.Count);
                for (int i = 0; i < c_tortoise_fly.Count; i++)
                {
                    sw.WriteLine(c_tortoise_fly[i].id + " " + c_tortoise_fly[i].oRect.X + " " + (mapHeight - c_tortoise_fly[i].oRect.Bottom) + " " + c_tortoise_fly[i].oRect.Width + " " + c_tortoise_fly[i].oRect.Height);
                }
                sw.WriteLine("tortoise_red" + " " + c_tortoise_red.Count);
                for (int i = 0; i < c_tortoise_red.Count; i++)
                {
                    sw.WriteLine(c_tortoise_red[i].id + " " + c_tortoise_red[i].oRect.X + " " + (mapHeight - c_tortoise_red[i].oRect.Bottom) + " " + c_tortoise_red[i].oRect.Width + " " + c_tortoise_red[i].oRect.Height);
                }
                sw.WriteLine("tree" + " " + c_tree.Count);
                for (int i = 0; i < c_tree.Count; i++)
                {
                    sw.WriteLine(c_tree[i].id + " " + c_tree[i].oRect.X + " " + (mapHeight - c_tree[i].oRect.Bottom) + " " + c_tree[i].oRect.Width + " " + c_tree[i].oRect.Height);
                }
                sw.WriteLine("tree_red" + " " + c_tree_red.Count);
                for (int i = 0; i < c_tree_red.Count; i++)
                {
                    sw.WriteLine(c_tree_red[i].id + " " + c_tree_red[i].oRect.X + " " + (mapHeight - c_tree_red[i].oRect.Bottom) + " " + c_tree_red[i].oRect.Width + " " + c_tree_red[i].oRect.Height);
                }
                sw.WriteLine("tree_red_shoot" + " " + c_tree_red_shoot.Count);
                for (int i = 0; i < c_tree_red_shoot.Count; i++)
                {
                    sw.WriteLine(c_tree_red_shoot[i].id + " " + c_tree_red_shoot[i].oRect.X + " " + (mapHeight - c_tree_red_shoot[i].oRect.Bottom) + " " + c_tree_red_shoot[i].oRect.Width + " " + c_tree_red_shoot[i].oRect.Height);
                }
                sw.WriteLine("tree_shoot" + " " + c_tree_shoot.Count);
                for (int i = 0; i < c_tree_shoot.Count; i++)
                {
                    sw.WriteLine(c_tree_shoot[i].id + " " + c_tree_shoot[i].oRect.X + " " + (mapHeight - c_tree_shoot[i].oRect.Bottom) + " " + c_tree_shoot[i].oRect.Width + " " + c_tree_shoot[i].oRect.Height);
                }
                sw.WriteLine("uprise" + " " + c_uprise.Count);
                for (int i = 0; i < c_uprise.Count; i++)
                {
                    sw.WriteLine(c_uprise[i].id + " " + c_uprise[i].oRect.X + " " + (mapHeight - c_uprise[i].oRect.Bottom) + " " + c_uprise[i].oRect.Width + " " + c_uprise[i].oRect.Height + " " + c_uprise[i].gameObject.vx+" "+c_uprise[i].gameObject.vy);
                }
                sw.WriteLine("music" + " " + c_music.Count);
                for (int i = 0; i < c_music.Count; i++)
                {
                    sw.WriteLine(c_music[i].id + " " + c_music[i].oRect.X + " " + (mapHeight - c_music[i].oRect.Bottom) + " " + c_music[i].oRect.Width + " " + c_music[i].oRect.Height);
                }
                sw.Close();
            }
        }
       
     
        bool set = false;
        private void btSetRegions_Click(object sender, EventArgs e)
        {
            set = !set;
            if (set)
                btSetRegions.Text = "set Regions: on";
            else
                btSetRegions.Text = "set Regions: off";
        }
       

        
       

        
            
    }
}

