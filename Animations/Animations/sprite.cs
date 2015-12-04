using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Animations
{
    class sprite : PictureBox
    {
        public static int count=0;
        public int x, y, c, w, h;
        public int id;
        public string type;
        public sprite() {
            id = count;
            count++;
        }        
    }
}
