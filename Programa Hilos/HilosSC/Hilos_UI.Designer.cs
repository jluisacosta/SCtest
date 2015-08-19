namespace HilosSC
{
    partial class Hilos_UI
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
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.toolStripLabel1 = new System.Windows.Forms.ToolStripLabel();
            this.tb_cantidad = new System.Windows.Forms.ToolStripTextBox();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.boton_crear = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.boton_iniciar = new System.Windows.Forms.ToolStripButton();
            this.boton_pausa = new System.Windows.Forms.ToolStripButton();
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.tableLayoutPanel4 = new System.Windows.Forms.TableLayoutPanel();
            this.lb_resultado = new System.Windows.Forms.ListBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.tableLayoutPanel3 = new System.Windows.Forms.TableLayoutPanel();
            this.b_carga2 = new System.Windows.Forms.Button();
            this.lb_arch2 = new System.Windows.Forms.ListBox();
            this.tb_arch2 = new System.Windows.Forms.TextBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.tableLayoutPanel2 = new System.Windows.Forms.TableLayoutPanel();
            this.b_carga1 = new System.Windows.Forms.Button();
            this.lb_arch1 = new System.Windows.Forms.ListBox();
            this.tb_arch1 = new System.Windows.Forms.TextBox();
            this.boton_abortar = new System.Windows.Forms.ToolStripButton();
            this.toolStrip1.SuspendLayout();
            this.tableLayoutPanel1.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.tableLayoutPanel4.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.tableLayoutPanel3.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.tableLayoutPanel2.SuspendLayout();
            this.SuspendLayout();
            // 
            // toolStrip1
            // 
            this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripLabel1,
            this.tb_cantidad,
            this.toolStripSeparator2,
            this.boton_crear,
            this.toolStripSeparator1,
            this.boton_iniciar,
            this.boton_pausa,
            this.boton_abortar});
            this.toolStrip1.LayoutStyle = System.Windows.Forms.ToolStripLayoutStyle.Flow;
            this.toolStrip1.Location = new System.Drawing.Point(0, 0);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.Size = new System.Drawing.Size(694, 23);
            this.toolStrip1.TabIndex = 0;
            this.toolStrip1.Text = "toolStrip1";
            // 
            // toolStripLabel1
            // 
            this.toolStripLabel1.Font = new System.Drawing.Font("Tahoma", 8.25F);
            this.toolStripLabel1.Margin = new System.Windows.Forms.Padding(0, 4, 0, 2);
            this.toolStripLabel1.Name = "toolStripLabel1";
            this.toolStripLabel1.Size = new System.Drawing.Size(108, 13);
            this.toolStripLabel1.Text = "  Números a escribir :";
            // 
            // tb_cantidad
            // 
            this.tb_cantidad.BackColor = System.Drawing.SystemColors.Info;
            this.tb_cantidad.Font = new System.Drawing.Font("Tahoma", 8F);
            this.tb_cantidad.Name = "tb_cantidad";
            this.tb_cantidad.Size = new System.Drawing.Size(70, 20);
            this.tb_cantidad.Text = "1000000";
            this.tb_cantidad.TextBoxTextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(6, 23);
            // 
            // boton_crear
            // 
            this.boton_crear.Image = global::HilosSC.Properties.Resources._1409377260_69485;
            this.boton_crear.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.boton_crear.Name = "boton_crear";
            this.boton_crear.Size = new System.Drawing.Size(97, 20);
            this.boton_crear.Text = "Crear archivos";
            this.boton_crear.Click += new System.EventHandler(this.boton_crear_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(6, 23);
            // 
            // boton_iniciar
            // 
            this.boton_iniciar.Image = global::HilosSC.Properties.Resources._1409377125_69454;
            this.boton_iniciar.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.boton_iniciar.Name = "boton_iniciar";
            this.boton_iniciar.Size = new System.Drawing.Size(56, 20);
            this.boton_iniciar.Text = "Iniciar";
            this.boton_iniciar.ToolTipText = "Iniciar ejecución de hilos";
            this.boton_iniciar.Click += new System.EventHandler(this.boton_iniciar_Click);
            // 
            // boton_pausa
            // 
            this.boton_pausa.Image = global::HilosSC.Properties.Resources._1409377247_69837;
            this.boton_pausa.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.boton_pausa.Name = "boton_pausa";
            this.boton_pausa.Size = new System.Drawing.Size(56, 20);
            this.boton_pausa.Text = "Pausa";
            this.boton_pausa.Click += new System.EventHandler(this.boton_pausa_Click);
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.ColumnCount = 3;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.tableLayoutPanel1.Controls.Add(this.groupBox3, 0, 0);
            this.tableLayoutPanel1.Controls.Add(this.groupBox2, 0, 0);
            this.tableLayoutPanel1.Controls.Add(this.groupBox1, 0, 0);
            this.tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel1.Location = new System.Drawing.Point(0, 23);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 1;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 477F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(694, 495);
            this.tableLayoutPanel1.TabIndex = 3;
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.tableLayoutPanel4);
            this.groupBox3.Dock = System.Windows.Forms.DockStyle.Fill;
            this.groupBox3.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox3.ForeColor = System.Drawing.Color.White;
            this.groupBox3.Location = new System.Drawing.Point(472, 10);
            this.groupBox3.Margin = new System.Windows.Forms.Padding(10);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(212, 475);
            this.groupBox3.TabIndex = 2;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Resultado";
            // 
            // tableLayoutPanel4
            // 
            this.tableLayoutPanel4.ColumnCount = 1;
            this.tableLayoutPanel4.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel4.Controls.Add(this.lb_resultado, 0, 0);
            this.tableLayoutPanel4.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel4.Location = new System.Drawing.Point(3, 18);
            this.tableLayoutPanel4.Name = "tableLayoutPanel4";
            this.tableLayoutPanel4.RowCount = 2;
            this.tableLayoutPanel4.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel4.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 40F));
            this.tableLayoutPanel4.Size = new System.Drawing.Size(206, 454);
            this.tableLayoutPanel4.TabIndex = 0;
            // 
            // lb_resultado
            // 
            this.lb_resultado.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lb_resultado.FormattingEnabled = true;
            this.lb_resultado.ItemHeight = 16;
            this.lb_resultado.Location = new System.Drawing.Point(10, 5);
            this.lb_resultado.Margin = new System.Windows.Forms.Padding(10, 5, 10, 5);
            this.lb_resultado.Name = "lb_resultado";
            this.lb_resultado.Size = new System.Drawing.Size(186, 404);
            this.lb_resultado.TabIndex = 1;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.tableLayoutPanel3);
            this.groupBox2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.groupBox2.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox2.ForeColor = System.Drawing.Color.White;
            this.groupBox2.Location = new System.Drawing.Point(241, 10);
            this.groupBox2.Margin = new System.Windows.Forms.Padding(10);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(211, 475);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Archivo 2";
            // 
            // tableLayoutPanel3
            // 
            this.tableLayoutPanel3.ColumnCount = 1;
            this.tableLayoutPanel3.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel3.Controls.Add(this.b_carga2, 0, 2);
            this.tableLayoutPanel3.Controls.Add(this.lb_arch2, 0, 0);
            this.tableLayoutPanel3.Controls.Add(this.tb_arch2, 0, 1);
            this.tableLayoutPanel3.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel3.Location = new System.Drawing.Point(3, 18);
            this.tableLayoutPanel3.Name = "tableLayoutPanel3";
            this.tableLayoutPanel3.RowCount = 3;
            this.tableLayoutPanel3.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel3.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 30F));
            this.tableLayoutPanel3.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 40F));
            this.tableLayoutPanel3.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.tableLayoutPanel3.Size = new System.Drawing.Size(205, 454);
            this.tableLayoutPanel3.TabIndex = 0;
            // 
            // b_carga2
            // 
            this.b_carga2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.b_carga2.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.b_carga2.ForeColor = System.Drawing.Color.SteelBlue;
            this.b_carga2.Location = new System.Drawing.Point(3, 417);
            this.b_carga2.Name = "b_carga2";
            this.b_carga2.Size = new System.Drawing.Size(199, 34);
            this.b_carga2.TabIndex = 0;
            this.b_carga2.Text = "Cargar ...";
            this.b_carga2.UseVisualStyleBackColor = true;
            this.b_carga2.Click += new System.EventHandler(this.b_carga_Click);
            // 
            // lb_arch2
            // 
            this.lb_arch2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lb_arch2.FormattingEnabled = true;
            this.lb_arch2.ItemHeight = 16;
            this.lb_arch2.Location = new System.Drawing.Point(10, 5);
            this.lb_arch2.Margin = new System.Windows.Forms.Padding(10, 5, 10, 5);
            this.lb_arch2.Name = "lb_arch2";
            this.lb_arch2.Size = new System.Drawing.Size(185, 374);
            this.lb_arch2.TabIndex = 1;
            // 
            // tb_arch2
            // 
            this.tb_arch2.Dock = System.Windows.Forms.DockStyle.Top;
            this.tb_arch2.Location = new System.Drawing.Point(3, 387);
            this.tb_arch2.Name = "tb_arch2";
            this.tb_arch2.ReadOnly = true;
            this.tb_arch2.Size = new System.Drawing.Size(199, 22);
            this.tb_arch2.TabIndex = 2;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.tableLayoutPanel2);
            this.groupBox1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.groupBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox1.ForeColor = System.Drawing.Color.White;
            this.groupBox1.Location = new System.Drawing.Point(10, 10);
            this.groupBox1.Margin = new System.Windows.Forms.Padding(10);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(211, 475);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Archivo 1";
            // 
            // tableLayoutPanel2
            // 
            this.tableLayoutPanel2.ColumnCount = 1;
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel2.Controls.Add(this.b_carga1, 0, 2);
            this.tableLayoutPanel2.Controls.Add(this.lb_arch1, 0, 0);
            this.tableLayoutPanel2.Controls.Add(this.tb_arch1, 0, 1);
            this.tableLayoutPanel2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel2.Location = new System.Drawing.Point(3, 18);
            this.tableLayoutPanel2.Name = "tableLayoutPanel2";
            this.tableLayoutPanel2.RowCount = 3;
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 30F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 40F));
            this.tableLayoutPanel2.Size = new System.Drawing.Size(205, 454);
            this.tableLayoutPanel2.TabIndex = 0;
            // 
            // b_carga1
            // 
            this.b_carga1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.b_carga1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.b_carga1.ForeColor = System.Drawing.Color.SteelBlue;
            this.b_carga1.Location = new System.Drawing.Point(3, 417);
            this.b_carga1.Name = "b_carga1";
            this.b_carga1.Size = new System.Drawing.Size(199, 34);
            this.b_carga1.TabIndex = 0;
            this.b_carga1.Text = "Cargar ...";
            this.b_carga1.UseVisualStyleBackColor = true;
            this.b_carga1.Click += new System.EventHandler(this.b_carga_Click);
            // 
            // lb_arch1
            // 
            this.lb_arch1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lb_arch1.FormattingEnabled = true;
            this.lb_arch1.ItemHeight = 16;
            this.lb_arch1.Location = new System.Drawing.Point(10, 5);
            this.lb_arch1.Margin = new System.Windows.Forms.Padding(10, 5, 10, 5);
            this.lb_arch1.Name = "lb_arch1";
            this.lb_arch1.Size = new System.Drawing.Size(185, 374);
            this.lb_arch1.TabIndex = 1;
            // 
            // tb_arch1
            // 
            this.tb_arch1.Dock = System.Windows.Forms.DockStyle.Top;
            this.tb_arch1.Location = new System.Drawing.Point(3, 387);
            this.tb_arch1.Name = "tb_arch1";
            this.tb_arch1.ReadOnly = true;
            this.tb_arch1.Size = new System.Drawing.Size(199, 22);
            this.tb_arch1.TabIndex = 2;
            // 
            // boton_abortar
            // 
            this.boton_abortar.Enabled = false;
            this.boton_abortar.Image = global::HilosSC.Properties.Resources._1409378451_69833;
            this.boton_abortar.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.boton_abortar.Name = "boton_abortar";
            this.boton_abortar.Size = new System.Drawing.Size(64, 20);
            this.boton_abortar.Text = "Abortar";
            this.boton_abortar.Click += new System.EventHandler(this.boton_abortar_Click);
            // 
            // Hilos_UI
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.SteelBlue;
            this.ClientSize = new System.Drawing.Size(694, 518);
            this.Controls.Add(this.tableLayoutPanel1);
            this.Controls.Add(this.toolStrip1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximumSize = new System.Drawing.Size(1000, 600);
            this.Name = "Hilos_UI";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = " [ Manejo de Hilos ]";
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
            this.tableLayoutPanel1.ResumeLayout(false);
            this.groupBox3.ResumeLayout(false);
            this.tableLayoutPanel4.ResumeLayout(false);
            this.groupBox2.ResumeLayout(false);
            this.tableLayoutPanel3.ResumeLayout(false);
            this.tableLayoutPanel3.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.tableLayoutPanel2.ResumeLayout(false);
            this.tableLayoutPanel2.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ToolStrip toolStrip1;
        private System.Windows.Forms.ToolStripButton boton_crear;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripButton boton_iniciar;
        private System.Windows.Forms.ToolStripButton boton_pausa;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel2;
        private System.Windows.Forms.Button b_carga1;
        private System.Windows.Forms.ListBox lb_arch1;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel4;
        private System.Windows.Forms.ListBox lb_resultado;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel3;
        private System.Windows.Forms.Button b_carga2;
        private System.Windows.Forms.ListBox lb_arch2;
        private System.Windows.Forms.ToolStripTextBox tb_cantidad;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.ToolStripLabel toolStripLabel1;
        private System.Windows.Forms.TextBox tb_arch2;
        private System.Windows.Forms.TextBox tb_arch1;
        private System.Windows.Forms.ToolStripButton boton_abortar;

    }
}

