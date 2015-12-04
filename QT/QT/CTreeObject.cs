using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
namespace QT
{
    class CTreeObject
    {
        public int id = -1;
        public Rectangle oRect;
        public GameObject gameObject;
        public CTreeObject(Rectangle _r) {
            oRect = _r;            
        }
        public CTreeObject(GameObject _gameObject)
        {
            gameObject = _gameObject;
        }
        public CTreeObject(int _id, Rectangle _r, GameObject _g)
        {
            id = _id;
            oRect = _r;
            gameObject = _g;
        }
        public CTreeObject(int _id, Rectangle _r) {
            oRect = _r;
            id = _id;
        }
        public CTreeObject(int _id)
        {
            id = _id;
        }
        public CTreeObject()
        {

        }

    }
}
