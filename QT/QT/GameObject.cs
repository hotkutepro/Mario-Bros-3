using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
enum typeO { _null,brick, land, tortoise, tortoise_fly, tortoise_red,mushroom_red,leaf,star,coin,question_block,tarnooki,tarnooki_fly,tree,tree_red,tree_shoot,
                    tree_red_shoot,drain,p}
namespace QT
{
    class GameObject:PictureBox
    {

        public int id;
        public int x0, y0;
        public  typeO type;        
        public GameObject(typeO t)
        {
            type = t;            
        }
        public GameObject(int _id, typeO t)
        {
            id = _id;
            type = t;
        }
        public GameObject() { }        
    }
}
