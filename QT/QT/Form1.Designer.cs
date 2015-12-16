namespace QT
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.panel1 = new System.Windows.Forms.Panel();
            this.pbImgMap = new System.Windows.Forms.PictureBox();
            this.button2 = new System.Windows.Forms.Button();
            this.panel2 = new System.Windows.Forms.Panel();
            this.btRemove = new System.Windows.Forms.Button();
            this.btReset = new System.Windows.Forms.Button();
            this.pleaf = new System.Windows.Forms.Panel();
            this.btTree_Red_Shoot = new System.Windows.Forms.Button();
            this.btP = new System.Windows.Forms.Button();
            this.btTree_red = new System.Windows.Forms.Button();
            this.btDrain = new System.Windows.Forms.Button();
            this.btTree_Shoot = new System.Windows.Forms.Button();
            this.btTree = new System.Windows.Forms.Button();
            this.pTortoise_red = new System.Windows.Forms.Panel();
            this.btTarnooki = new System.Windows.Forms.Button();
            this.btQuestion_Block = new System.Windows.Forms.Button();
            this.btTarnooki_fly = new System.Windows.Forms.Button();
            this.btCoin = new System.Windows.Forms.Button();
            this.bt_leaf = new System.Windows.Forms.Button();
            this.btStar = new System.Windows.Forms.Button();
            this.pTortoise = new System.Windows.Forms.Panel();
            this.btMushroom_red = new System.Windows.Forms.Button();
            this.btTortoise_red = new System.Windows.Forms.Button();
            this.btTortoise_fly = new System.Windows.Forms.Button();
            this.btBrick = new System.Windows.Forms.Button();
            this.btBox = new System.Windows.Forms.Button();
            this.btLand = new System.Windows.Forms.Button();
            this.btTortoise = new System.Windows.Forms.Button();
            this.panel3 = new System.Windows.Forms.Panel();
            this.tby2 = new System.Windows.Forms.TextBox();
            this.tby1 = new System.Windows.Forms.TextBox();
            this.tbx2 = new System.Windows.Forms.TextBox();
            this.tbx1 = new System.Windows.Forms.TextBox();
            this.lby1 = new System.Windows.Forms.Label();
            this.lbx2 = new System.Windows.Forms.Label();
            this.lby2 = new System.Windows.Forms.Label();
            this.lbx1 = new System.Windows.Forms.Label();
            this.btSetRegions = new System.Windows.Forms.Button();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.btCheckOut = new System.Windows.Forms.Button();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pbImgMap)).BeginInit();
            this.panel2.SuspendLayout();
            this.pleaf.SuspendLayout();
            this.pTortoise_red.SuspendLayout();
            this.pTortoise.SuspendLayout();
            this.panel3.SuspendLayout();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.AutoScroll = true;
            this.panel1.Controls.Add(this.pbImgMap);
            this.panel1.Location = new System.Drawing.Point(12, 46);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(779, 605);
            this.panel1.TabIndex = 0;
            // 
            // pbImgMap
            // 
            this.pbImgMap.Location = new System.Drawing.Point(0, 1);
            this.pbImgMap.Name = "pbImgMap";
            this.pbImgMap.Size = new System.Drawing.Size(100, 50);
            this.pbImgMap.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize;
            this.pbImgMap.TabIndex = 1;
            this.pbImgMap.TabStop = false;
            this.pbImgMap.Paint += new System.Windows.Forms.PaintEventHandler(this.pbImgMap_Paint);
            this.pbImgMap.MouseDown += new System.Windows.Forms.MouseEventHandler(this.pbImgMap_MouseDown);
            this.pbImgMap.MouseMove += new System.Windows.Forms.MouseEventHandler(this.pbImgMap_MouseMove);
            this.pbImgMap.MouseUp += new System.Windows.Forms.MouseEventHandler(this.pbImgMap_MouseUp);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(220, 12);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 23);
            this.button2.TabIndex = 1;
            this.button2.Text = "SrcMap";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.btSrcMap_Click);
            // 
            // panel2
            // 
            this.panel2.AutoScroll = true;
            this.panel2.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel2.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(255)))));
            this.panel2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel2.Controls.Add(this.btRemove);
            this.panel2.Controls.Add(this.btReset);
            this.panel2.Controls.Add(this.pleaf);
            this.panel2.Controls.Add(this.pTortoise_red);
            this.panel2.Controls.Add(this.pTortoise);
            this.panel2.Controls.Add(this.panel3);
            this.panel2.Location = new System.Drawing.Point(807, 46);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(532, 605);
            this.panel2.TabIndex = 2;
            // 
            // btRemove
            // 
            this.btRemove.Location = new System.Drawing.Point(121, 3);
            this.btRemove.Name = "btRemove";
            this.btRemove.Size = new System.Drawing.Size(75, 23);
            this.btRemove.TabIndex = 17;
            this.btRemove.Text = "Remove: off";
            this.btRemove.UseVisualStyleBackColor = true;
            this.btRemove.Click += new System.EventHandler(this.btRemove_Click);
            // 
            // btReset
            // 
            this.btReset.Location = new System.Drawing.Point(6, -2);
            this.btReset.Name = "btReset";
            this.btReset.Size = new System.Drawing.Size(75, 23);
            this.btReset.TabIndex = 16;
            this.btReset.Text = "Reset_index";
            this.btReset.UseVisualStyleBackColor = true;
            this.btReset.Click += new System.EventHandler(this.btReset_Click);
            // 
            // pleaf
            // 
            this.pleaf.Controls.Add(this.btTree_Red_Shoot);
            this.pleaf.Controls.Add(this.btP);
            this.pleaf.Controls.Add(this.btTree_red);
            this.pleaf.Controls.Add(this.btDrain);
            this.pleaf.Controls.Add(this.btTree_Shoot);
            this.pleaf.Controls.Add(this.btTree);
            this.pleaf.Location = new System.Drawing.Point(27, 424);
            this.pleaf.Name = "pleaf";
            this.pleaf.Size = new System.Drawing.Size(324, 129);
            this.pleaf.TabIndex = 0;
            // 
            // btTree_Red_Shoot
            // 
            this.btTree_Red_Shoot.Location = new System.Drawing.Point(201, 103);
            this.btTree_Red_Shoot.Name = "btTree_Red_Shoot";
            this.btTree_Red_Shoot.Size = new System.Drawing.Size(99, 23);
            this.btTree_Red_Shoot.TabIndex = 2;
            this.btTree_Red_Shoot.Text = "Tree_Red_Shoot";
            this.btTree_Red_Shoot.UseVisualStyleBackColor = true;
            this.btTree_Red_Shoot.Click += new System.EventHandler(this.btTree_Red_Shoot_Click);
            // 
            // btP
            // 
            this.btP.Location = new System.Drawing.Point(0, 18);
            this.btP.Name = "btP";
            this.btP.Size = new System.Drawing.Size(39, 23);
            this.btP.TabIndex = 3;
            this.btP.Text = "P";
            this.btP.UseVisualStyleBackColor = true;
            this.btP.Click += new System.EventHandler(this.btP_Click);
            // 
            // btTree_red
            // 
            this.btTree_red.Location = new System.Drawing.Point(213, 3);
            this.btTree_red.Name = "btTree_red";
            this.btTree_red.Size = new System.Drawing.Size(75, 23);
            this.btTree_red.TabIndex = 1;
            this.btTree_red.Text = "Tree_red";
            this.btTree_red.UseVisualStyleBackColor = true;
            this.btTree_red.Click += new System.EventHandler(this.btTree_red_Click);
            // 
            // btDrain
            // 
            this.btDrain.Location = new System.Drawing.Point(0, 47);
            this.btDrain.Name = "btDrain";
            this.btDrain.Size = new System.Drawing.Size(75, 23);
            this.btDrain.TabIndex = 1;
            this.btDrain.Text = "Drain";
            this.btDrain.UseVisualStyleBackColor = true;
            this.btDrain.Click += new System.EventHandler(this.btDrain_Click);
            // 
            // btTree_Shoot
            // 
            this.btTree_Shoot.Location = new System.Drawing.Point(211, 32);
            this.btTree_Shoot.Name = "btTree_Shoot";
            this.btTree_Shoot.Size = new System.Drawing.Size(75, 23);
            this.btTree_Shoot.TabIndex = 2;
            this.btTree_Shoot.Text = "Tree_Shoot";
            this.btTree_Shoot.UseVisualStyleBackColor = true;
            this.btTree_Shoot.Click += new System.EventHandler(this.btTree_Shoot_Click);
            // 
            // btTree
            // 
            this.btTree.Location = new System.Drawing.Point(213, 61);
            this.btTree.Name = "btTree";
            this.btTree.Size = new System.Drawing.Size(75, 23);
            this.btTree.TabIndex = 1;
            this.btTree.Text = "Tree";
            this.btTree.UseVisualStyleBackColor = true;
            this.btTree.Click += new System.EventHandler(this.btTree_Click);
            // 
            // pTortoise_red
            // 
            this.pTortoise_red.Controls.Add(this.btQuestion_Block);
            this.pTortoise_red.Controls.Add(this.btTarnooki_fly);
            this.pTortoise_red.Controls.Add(this.btCoin);
            this.pTortoise_red.Controls.Add(this.bt_leaf);
            this.pTortoise_red.Controls.Add(this.btStar);
            this.pTortoise_red.Location = new System.Drawing.Point(3, 293);
            this.pTortoise_red.Name = "pTortoise_red";
            this.pTortoise_red.Size = new System.Drawing.Size(324, 127);
            this.pTortoise_red.TabIndex = 3;
            // 
            // btTarnooki
            // 
            this.btTarnooki.Location = new System.Drawing.Point(0, 90);
            this.btTarnooki.Name = "btTarnooki";
            this.btTarnooki.Size = new System.Drawing.Size(75, 23);
            this.btTarnooki.TabIndex = 1;
            this.btTarnooki.Text = "Tarnooki";
            this.btTarnooki.UseVisualStyleBackColor = true;
            this.btTarnooki.Click += new System.EventHandler(this.btTarnooki_Click);
            // 
            // btQuestion_Block
            // 
            this.btQuestion_Block.Location = new System.Drawing.Point(229, 101);
            this.btQuestion_Block.Name = "btQuestion_Block";
            this.btQuestion_Block.Size = new System.Drawing.Size(95, 23);
            this.btQuestion_Block.TabIndex = 1;
            this.btQuestion_Block.Text = "Question_Block";
            this.btQuestion_Block.UseVisualStyleBackColor = true;
            this.btQuestion_Block.Click += new System.EventHandler(this.btQuestion_Block_Click);
            // 
            // btTarnooki_fly
            // 
            this.btTarnooki_fly.Location = new System.Drawing.Point(246, 0);
            this.btTarnooki_fly.Name = "btTarnooki_fly";
            this.btTarnooki_fly.Size = new System.Drawing.Size(75, 23);
            this.btTarnooki_fly.TabIndex = 1;
            this.btTarnooki_fly.Text = "Tarnooki_fly";
            this.btTarnooki_fly.UseVisualStyleBackColor = true;
            this.btTarnooki_fly.Click += new System.EventHandler(this.btTarnooki_fly_Click);
            // 
            // btCoin
            // 
            this.btCoin.Location = new System.Drawing.Point(0, 61);
            this.btCoin.Name = "btCoin";
            this.btCoin.Size = new System.Drawing.Size(75, 23);
            this.btCoin.TabIndex = 1;
            this.btCoin.Text = "Coin";
            this.btCoin.UseVisualStyleBackColor = true;
            this.btCoin.Click += new System.EventHandler(this.btCoin_Click);
            // 
            // bt_leaf
            // 
            this.bt_leaf.Location = new System.Drawing.Point(-4, 32);
            this.bt_leaf.Name = "bt_leaf";
            this.bt_leaf.Size = new System.Drawing.Size(75, 23);
            this.bt_leaf.TabIndex = 1;
            this.bt_leaf.Text = "Leaf";
            this.bt_leaf.UseVisualStyleBackColor = true;
            this.bt_leaf.Click += new System.EventHandler(this.bt_leaf_Click);
            // 
            // btStar
            // 
            this.btStar.Location = new System.Drawing.Point(0, 3);
            this.btStar.Name = "btStar";
            this.btStar.Size = new System.Drawing.Size(75, 23);
            this.btStar.TabIndex = 1;
            this.btStar.Text = "Star";
            this.btStar.UseVisualStyleBackColor = true;
            this.btStar.Click += new System.EventHandler(this.btStar_Click);
            // 
            // pTortoise
            // 
            this.pTortoise.Controls.Add(this.btTarnooki);
            this.pTortoise.Controls.Add(this.btMushroom_red);
            this.pTortoise.Controls.Add(this.btTortoise_red);
            this.pTortoise.Controls.Add(this.btTortoise_fly);
            this.pTortoise.Controls.Add(this.btBrick);
            this.pTortoise.Controls.Add(this.btBox);
            this.pTortoise.Controls.Add(this.btLand);
            this.pTortoise.Controls.Add(this.btTortoise);
            this.pTortoise.Location = new System.Drawing.Point(3, 160);
            this.pTortoise.Name = "pTortoise";
            this.pTortoise.Size = new System.Drawing.Size(324, 127);
            this.pTortoise.TabIndex = 3;
            // 
            // btMushroom_red
            // 
            this.btMushroom_red.Location = new System.Drawing.Point(235, 90);
            this.btMushroom_red.Name = "btMushroom_red";
            this.btMushroom_red.Size = new System.Drawing.Size(86, 23);
            this.btMushroom_red.TabIndex = 1;
            this.btMushroom_red.Text = "Mushroom_red";
            this.btMushroom_red.UseVisualStyleBackColor = true;
            this.btMushroom_red.Click += new System.EventHandler(this.btMushroom_red_Click);
            // 
            // btTortoise_red
            // 
            this.btTortoise_red.Location = new System.Drawing.Point(246, 61);
            this.btTortoise_red.Name = "btTortoise_red";
            this.btTortoise_red.Size = new System.Drawing.Size(75, 23);
            this.btTortoise_red.TabIndex = 1;
            this.btTortoise_red.Text = "Tortoise_red";
            this.btTortoise_red.UseVisualStyleBackColor = true;
            this.btTortoise_red.Click += new System.EventHandler(this.btTortoise_red_Click);
            // 
            // btTortoise_fly
            // 
            this.btTortoise_fly.Location = new System.Drawing.Point(246, 32);
            this.btTortoise_fly.Name = "btTortoise_fly";
            this.btTortoise_fly.Size = new System.Drawing.Size(75, 23);
            this.btTortoise_fly.TabIndex = 1;
            this.btTortoise_fly.Text = "Tortoise_fly";
            this.btTortoise_fly.UseVisualStyleBackColor = true;
            this.btTortoise_fly.Click += new System.EventHandler(this.btTortoise_fly_Click);
            // 
            // btBrick
            // 
            this.btBrick.Location = new System.Drawing.Point(177, 0);
            this.btBrick.Name = "btBrick";
            this.btBrick.Size = new System.Drawing.Size(75, 23);
            this.btBrick.TabIndex = 0;
            this.btBrick.Text = "Brick";
            this.btBrick.UseVisualStyleBackColor = true;
            this.btBrick.Click += new System.EventHandler(this.btBrick_Click);
            // 
            // btBox
            // 
            this.btBox.Location = new System.Drawing.Point(3, 32);
            this.btBox.Name = "btBox";
            this.btBox.Size = new System.Drawing.Size(75, 23);
            this.btBox.TabIndex = 2;
            this.btBox.Text = "Box";
            this.btBox.UseVisualStyleBackColor = true;
            this.btBox.Click += new System.EventHandler(this.btBox_Click);
            // 
            // btLand
            // 
            this.btLand.Location = new System.Drawing.Point(3, 61);
            this.btLand.Name = "btLand";
            this.btLand.Size = new System.Drawing.Size(75, 23);
            this.btLand.TabIndex = 1;
            this.btLand.Text = "Land";
            this.btLand.UseVisualStyleBackColor = true;
            this.btLand.Click += new System.EventHandler(this.btLand_Click);
            // 
            // btTortoise
            // 
            this.btTortoise.Location = new System.Drawing.Point(3, 3);
            this.btTortoise.Name = "btTortoise";
            this.btTortoise.Size = new System.Drawing.Size(75, 23);
            this.btTortoise.TabIndex = 1;
            this.btTortoise.Text = "Tortoise";
            this.btTortoise.UseVisualStyleBackColor = true;
            this.btTortoise.Click += new System.EventHandler(this.btTortoise_Click);
            // 
            // panel3
            // 
            this.panel3.Controls.Add(this.tby2);
            this.panel3.Controls.Add(this.tby1);
            this.panel3.Controls.Add(this.tbx2);
            this.panel3.Controls.Add(this.tbx1);
            this.panel3.Controls.Add(this.lby1);
            this.panel3.Controls.Add(this.lbx2);
            this.panel3.Controls.Add(this.lby2);
            this.panel3.Controls.Add(this.lbx1);
            this.panel3.Controls.Add(this.btSetRegions);
            this.panel3.Location = new System.Drawing.Point(3, 27);
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size(324, 127);
            this.panel3.TabIndex = 1;
            // 
            // tby2
            // 
            this.tby2.Location = new System.Drawing.Point(146, 80);
            this.tby2.Name = "tby2";
            this.tby2.Size = new System.Drawing.Size(100, 20);
            this.tby2.TabIndex = 8;
            this.tby2.Text = "0";
            // 
            // tby1
            // 
            this.tby1.Location = new System.Drawing.Point(146, 26);
            this.tby1.Name = "tby1";
            this.tby1.Size = new System.Drawing.Size(100, 20);
            this.tby1.TabIndex = 7;
            this.tby1.Text = "0";
            // 
            // tbx2
            // 
            this.tbx2.Location = new System.Drawing.Point(146, 50);
            this.tbx2.Name = "tbx2";
            this.tbx2.Size = new System.Drawing.Size(100, 20);
            this.tbx2.TabIndex = 6;
            this.tbx2.Text = "0";
            // 
            // tbx1
            // 
            this.tbx1.Location = new System.Drawing.Point(146, 5);
            this.tbx1.Name = "tbx1";
            this.tbx1.Size = new System.Drawing.Size(100, 20);
            this.tbx1.TabIndex = 5;
            this.tbx1.Text = "0";
            // 
            // lby1
            // 
            this.lby1.AutoSize = true;
            this.lby1.Location = new System.Drawing.Point(93, 29);
            this.lby1.Name = "lby1";
            this.lby1.Size = new System.Drawing.Size(30, 13);
            this.lby1.TabIndex = 4;
            this.lby1.Text = "y1 = ";
            // 
            // lbx2
            // 
            this.lbx2.AutoSize = true;
            this.lbx2.Location = new System.Drawing.Point(93, 57);
            this.lbx2.Name = "lbx2";
            this.lbx2.Size = new System.Drawing.Size(30, 13);
            this.lbx2.TabIndex = 3;
            this.lbx2.Text = "x2 = ";
            // 
            // lby2
            // 
            this.lby2.AutoSize = true;
            this.lby2.Location = new System.Drawing.Point(93, 87);
            this.lby2.Name = "lby2";
            this.lby2.Size = new System.Drawing.Size(30, 13);
            this.lby2.TabIndex = 2;
            this.lby2.Text = "y2 = ";
            // 
            // lbx1
            // 
            this.lbx1.AutoSize = true;
            this.lbx1.Location = new System.Drawing.Point(93, 8);
            this.lbx1.Name = "lbx1";
            this.lbx1.Size = new System.Drawing.Size(30, 13);
            this.lbx1.TabIndex = 1;
            this.lbx1.Text = "x1 = ";
            // 
            // btSetRegions
            // 
            this.btSetRegions.Location = new System.Drawing.Point(3, 3);
            this.btSetRegions.Name = "btSetRegions";
            this.btSetRegions.Size = new System.Drawing.Size(75, 39);
            this.btSetRegions.TabIndex = 0;
            this.btSetRegions.Text = "Set Regions: off";
            this.btSetRegions.UseVisualStyleBackColor = true;
            this.btSetRegions.Click += new System.EventHandler(this.btSetRegions_Click);
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(61, 4);
            // 
            // btCheckOut
            // 
            this.btCheckOut.Location = new System.Drawing.Point(338, 12);
            this.btCheckOut.Name = "btCheckOut";
            this.btCheckOut.Size = new System.Drawing.Size(75, 23);
            this.btCheckOut.TabIndex = 18;
            this.btCheckOut.Text = "Check out";
            this.btCheckOut.UseVisualStyleBackColor = true;
            this.btCheckOut.Click += new System.EventHandler(this.btCheckOut_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(128)))), ((int)(((byte)(255)))), ((int)(((byte)(128)))));
            this.ClientSize = new System.Drawing.Size(1351, 659);
            this.Controls.Add(this.btCheckOut);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.panel1);
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.Manual;
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pbImgMap)).EndInit();
            this.panel2.ResumeLayout(false);
            this.pleaf.ResumeLayout(false);
            this.pTortoise_red.ResumeLayout(false);
            this.pTortoise.ResumeLayout(false);
            this.panel3.ResumeLayout(false);
            this.panel3.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.PictureBox pbImgMap;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.Panel pleaf;
        private System.Windows.Forms.Panel pTortoise_red;
        private System.Windows.Forms.Panel pTortoise;
        private System.Windows.Forms.Panel panel3;
        private System.Windows.Forms.Button btDrain;
        private System.Windows.Forms.Button btTree;
        private System.Windows.Forms.Button btTarnooki;
        private System.Windows.Forms.Button btTree_red;
        private System.Windows.Forms.Button btTarnooki_fly;
        private System.Windows.Forms.Button btQuestion_Block;
        private System.Windows.Forms.Button btCoin;
        private System.Windows.Forms.Button btStar;
        private System.Windows.Forms.Button bt_leaf;
        private System.Windows.Forms.Button btTortoise_red;
        private System.Windows.Forms.Button btTortoise_fly;
        private System.Windows.Forms.Button btTortoise;
        private System.Windows.Forms.Button btMushroom_red;
        private System.Windows.Forms.Button btLand;
        private System.Windows.Forms.Button btBrick;
        private System.Windows.Forms.Button btReset;
        private System.Windows.Forms.Button btTree_Shoot;
        private System.Windows.Forms.Button btTree_Red_Shoot;
        private System.Windows.Forms.Button btP;
        private System.Windows.Forms.Button btCheckOut;
        private System.Windows.Forms.Button btRemove;
        private System.Windows.Forms.TextBox tby2;
        private System.Windows.Forms.TextBox tby1;
        private System.Windows.Forms.TextBox tbx2;
        private System.Windows.Forms.TextBox tbx1;
        private System.Windows.Forms.Label lby1;
        private System.Windows.Forms.Label lbx2;
        private System.Windows.Forms.Label lby2;
        private System.Windows.Forms.Label lbx1;
        private System.Windows.Forms.Button btSetRegions;
        private System.Windows.Forms.Button btBox;

    }
}

