using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Threading;

namespace HilosSC
{
    public partial class Hilos_UI : Form
    {
        private const uint MAX = 1000000;
        private HiloArchivo hilo1;
        private HiloArchivo hilo2;
        private HiloOperacion hiloR;
        public bool iniciado,pausado,terminado;

        public Hilos_UI()
        {
            InitializeComponent();
            Hilo.ui_principal = this;
            iniciado = pausado = terminado = false;
        }

        private void boton_crear_Click(object sender, EventArgs e)
        {
            FolderBrowserDialog dlg_carpeta;
            Random r;
            uint n;

            if (!iniciado)
            {
                try
                {
                    n = Convert.ToUInt32(tb_cantidad.Text);

                    if (n > 0 && n <= MAX)
                    {
                        dlg_carpeta = new FolderBrowserDialog();
                        dlg_carpeta.Description = "Seleccione la ubicación de destino para los archivos :";
                        if (dlg_carpeta.ShowDialog(this) == DialogResult.OK)
                        {
                            try
                            {
                                r = new Random(DateTime.Now.Millisecond);
                                this.creaArchivo(new FileStream(dlg_carpeta.SelectedPath + "\\Archivo1", FileMode.Create), n, r);
                                this.creaArchivo(new FileStream(dlg_carpeta.SelectedPath + "\\Archivo2", FileMode.Create), n, r);
                                MessageBox.Show("Los archivos fueron creados exitosamente en:\n\n" + dlg_carpeta.SelectedPath, "Archivos creados", MessageBoxButtons.OK, MessageBoxIcon.Information);
                            }
                            catch (IOException ioex) { MessageBox.Show(ioex.Message); }
                        }
                    }
                    else
                        MessageBox.Show("0 < Cantidad de números <= 1,000,000 !");
                }
                catch (OverflowException oex) { MessageBox.Show(oex.Message); }
                catch (FormatException fex) { MessageBox.Show(fex.Message); }
            }
        }

        private void creaArchivo(FileStream archivo,uint n,Random r)
        {
            BinaryWriter bw = new BinaryWriter(archivo);
            
            for (uint i = 0; i < n; bw.Write((float)(r.NextDouble() * 100)), i++) ;
            bw.Close();
        }

        private void b_carga_Click(object sender, EventArgs e)
        {
            OpenFileDialog dlg_abrir;

            if (!iniciado)
            {
                dlg_abrir = new OpenFileDialog();

                if (dlg_abrir.ShowDialog() == DialogResult.OK)
                {
                    if (sender.Equals(b_carga1))
                    {
                        hilo1 = new HiloArchivo(dlg_abrir.FileName, lb_arch1);
                        lb_arch1.Items.Clear();
                        tb_arch1.Text = dlg_abrir.FileName;
                        tb_arch1.SelectionStart = tb_arch1.Text.Length - 1;
                    }
                    else
                    {
                        hilo2 = new HiloArchivo(dlg_abrir.FileName, lb_arch2);
                        lb_arch2.Items.Clear();
                        tb_arch2.Text = dlg_abrir.FileName;
                        tb_arch2.SelectionStart = tb_arch2.Text.Length - 1;
                    }
                }
            }
        }


        private void boton_iniciar_Click(object sender, EventArgs e)
        {
            if (!iniciado)
            {
                if (hilo1 != null && hilo2 != null)
                {
                    if (hilo1.dameNumeroDatos() == hilo2.dameNumeroDatos())
                    {
                        lb_arch1.Items.Clear();
                        lb_arch2.Items.Clear();
                        lb_resultado.Items.Clear();
                        hilo1.comienza();
                        hilo2.comienza();
                        hiloR = new HiloOperacion(lb_resultado, lb_arch1, lb_arch2);
                        hiloR.comienza();
                    }
                    else
                        MessageBox.Show("El tamaño de los archivos es distinto.", "Error",MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
                else
                    MessageBox.Show("No se han cargdo los dos archivos!", "Error",MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else if(pausado)
            {
                boton_iniciar.Text = "Iniciar";
                hilo1.continua();
                hilo2.continua();
                hiloR.continua();
            }
        }

        private void boton_pausa_Click(object sender, EventArgs e)
        {
            if (hilo1 != null && hilo2!=null && hiloR!=null)
            {
                boton_iniciar.Text = "Continuar";
                hilo1.suspende();
                hilo2.suspende();
                hiloR.suspende();
            }
        }

        private void boton_abortar_Click(object sender, EventArgs e)
        {
            if (hilo1 != null && hilo2 != null && hiloR != null)
            {
                boton_iniciar.Text = "Iniciar";
                hilo1.aborta();
                hilo2.aborta();
                hiloR.aborta();
            }
        }
    }
}
