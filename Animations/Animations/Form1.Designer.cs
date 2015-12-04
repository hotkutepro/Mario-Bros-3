namespace Animations
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
            this.panel1 = new System.Windows.Forms.Panel();
            this.p_mapImage = new System.Windows.Forms.PictureBox();
            this.btOpentAllSprite = new System.Windows.Forms.Button();
            this.btEnter = new System.Windows.Forms.Button();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.p_mapImage)).BeginInit();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.AutoScroll = true;
            this.panel1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(0)))));
            this.panel1.Controls.Add(this.p_mapImage);
            this.panel1.Location = new System.Drawing.Point(12, 12);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(942, 587);
            this.panel1.TabIndex = 0;
            // 
            // p_mapImage
            // 
            this.p_mapImage.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(128)))), ((int)(((byte)(255)))), ((int)(((byte)(255)))));
            this.p_mapImage.Location = new System.Drawing.Point(0, 0);
            this.p_mapImage.Name = "p_mapImage";
            this.p_mapImage.Size = new System.Drawing.Size(1024, 1024);
            this.p_mapImage.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize;
            this.p_mapImage.TabIndex = 0;
            this.p_mapImage.TabStop = false;
            // 
            // btOpentAllSprite
            // 
            this.btOpentAllSprite.Location = new System.Drawing.Point(1001, 103);
            this.btOpentAllSprite.Name = "btOpentAllSprite";
            this.btOpentAllSprite.Size = new System.Drawing.Size(87, 23);
            this.btOpentAllSprite.TabIndex = 1;
            this.btOpentAllSprite.Text = "OpentAllSprite";
            this.btOpentAllSprite.UseVisualStyleBackColor = true;
            this.btOpentAllSprite.Click += new System.EventHandler(this.btOpentAllSprite_Click);
            // 
            // btEnter
            // 
            this.btEnter.Location = new System.Drawing.Point(1013, 147);
            this.btEnter.Name = "btEnter";
            this.btEnter.Size = new System.Drawing.Size(75, 23);
            this.btEnter.TabIndex = 4;
            this.btEnter.Text = "Enter";
            this.btEnter.UseVisualStyleBackColor = true;
            this.btEnter.Click += new System.EventHandler(this.btEnter_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.ClientSize = new System.Drawing.Size(1147, 611);
            this.Controls.Add(this.btEnter);
            this.Controls.Add(this.btOpentAllSprite);
            this.Controls.Add(this.panel1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.p_mapImage)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.PictureBox p_mapImage;
        private System.Windows.Forms.Button btOpentAllSprite;
        private System.Windows.Forms.Button btEnter;
    }
}

