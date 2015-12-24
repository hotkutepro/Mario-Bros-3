using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace QT
{    
    class QNode
    {
        public const int minSize = 257;
        //QNode tl,tr,bl,br;                
        public QNode[] Node=new QNode[4];
        public int NodeID;
        public Rectangle nRect;
        public List<CTreeObject> objects= new List<CTreeObject>();
        public bool canSplit()
        {
            return nRect.Width > minSize;
        }
        public void Split()
        {
            int sw = nRect.Width / 2;
            int sh = nRect.Height / 2;
            if (nRect.Width < minSize || nRect.Height < minSize)
                return;
            int x = nRect.X;
            int y = nRect.Y;
            int id=NodeID*10;
            Node[0] = new QNode(id + 1, new Rectangle(x, y, sw, sh));
            Node[1] = new QNode(id + 2, new Rectangle(x + sw, y, sw, sh));
            Node[2] = new QNode(id + 3, new Rectangle(x, y + sh, sw, sh));
            Node[3] = new QNode(id + 4, new Rectangle(x + sw, y + sh, sw, sh));

        }
        //Xác định xem _object.oRect va chạm với QNode nào,
        //thêm _object vào node mà nó va chạm
        public void AddObjectInNode(CTreeObject _object)
        {
            int index = -1;
            int sw = nRect.X + nRect.Width / 2;
            int sh = nRect.Y + nRect.Height / 2;
            bool top=(_object.oRect.Y+_object.oRect.Height <= sh);//hoàn toàn ở trên
            bool bottom = _object.oRect.Y >= sh;
            bool left = _object.oRect.X + _object.oRect.Width <= sw;
            bool right = _object.oRect.X >= sw;
            if (top && left)
                Node[0].Insert(_object);
            else if (top && right)
                Node[1].Insert(_object);
            else if (bottom && left)
                Node[2].Insert(_object);
            else if (bottom && right)
                Node[3].Insert(_object);
            else if (top && !left && !right)
            {
                Node[0].Insert(_object);
                Node[1].Insert(_object);
            }
            else if (bottom && !right && !left)
            {
                Node[2].Insert(_object);
                Node[3].Insert(_object);
            }
            else if (left && !top && !bottom)
            {
                Node[2].Insert(_object);
                Node[0].Insert(_object);
            }
            else if (right && !top && !bottom)
            {
                Node[1].Insert(_object);
                Node[3].Insert(_object);
            }
            else if (!right && !top && !left && !bottom)
            {
                Node[1].Insert(_object);
                Node[3].Insert(_object);
                Node[2].Insert(_object);
                Node[0].Insert(_object);
            }            
        }
        public void Insert(CTreeObject _object)
        {
            if (Node[0] != null)
            {
                AddObjectInNode(_object);
                return;
            }                       
            objects.Add(_object);
            if (!canSplit())
                return;
            if (Node[0] == null)
                Split();
            int i = 0;
            while(i<objects.Count)
            {                
                AddObjectInNode(objects[i]);
                objects.RemoveAt(i);
            }


    }


        public QNode(int id, Rectangle rect) {
            NodeID = id;
            nRect = rect;
        }
        
        
        public static List<QNode> l_QNode = new List<QNode>(); //danh sach cac node
        public static int count_QNode = 0;
        public List<QNode> getListQNode()
        {
            if (this != null) 
            { 
                l_QNode.Add(this);
                count_QNode++;
            }
            if (Node[0] != null) 
            { 
            Node[0].getListQNode();
            Node[1].getListQNode();
            Node[2].getListQNode();
            Node[3].getListQNode();
            }
            return l_QNode;
        }

        public void Writer_QNode()
        {
            using (StreamWriter sw = new StreamWriter("C:/Users/pumpa/Desktop/Mario-Bros-3-final.git/trunk/NMPTG/QNode.txt"))
            {
                sw.Write(count_QNode + "\r\n");
                foreach(QNode i in l_QNode)
                    sw.Write(i.NodeID + " " + i.nRect.Top + " " + i.nRect.Left + " " + i.nRect.Right + " " + i.nRect.Bottom + "\r\n");
            }
        }
        public void ghifile()
        {
            using (StreamWriter w = new StreamWriter("C:/Users/pumpa/Desktop/Mario-Bros-3-final.git/trunk/NMPTG/OiNode.txt"))
            {
                w.Write(nla.Count+"\r\n");
                foreach (QNode i in nla)
                {
                    if (i.objects.Count >0) {                        
                        w.Write(i.NodeID + " "+i.objects.Count+" ");
                    foreach (CTreeObject j in i.objects)
                        w.Write(j.id + " ");
                    w.Write("\r\n");
                    }
                }
            }
        }
       public static List<QNode> nla = new List<QNode>();
        public List<QNode> nodela()
        {
            
            if (Node[0] == null)
                nla.Add(this);
            else { 
            Node[0].nodela();
            Node[1].nodela();
            Node[2].nodela();
            Node[3].nodela();
            }
            return nla;
        }
        public int count()
        {
            int n = 0;
            if (Node[0] == null)
                return objects.Count;
            n += Node[0].count();
            n += Node[1].count();
            n += Node[2].count();
            n += Node[3].count();
            return n;
        }
    }
}
