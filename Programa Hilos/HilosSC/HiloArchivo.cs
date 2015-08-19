using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.IO;
using System.Windows.Forms;

namespace HilosSC
{
    class HiloArchivo:Hilo
    {
        private string ruta_archivo;

        public HiloArchivo(string ruta_archivo,ListBox lb_archivo):base(lb_archivo)
        {
            FileStream secuencia;

            try
            {
                this.lb_datos = lb_archivo;
                this.ruta_archivo = ruta_archivo;
                secuencia = new FileStream(ruta_archivo, FileMode.Open);
                n = (uint)secuencia.Length/sizeof(float);
                secuencia.Close();
            }
            catch (IOException ioex){   MessageBox.Show(ioex.Message);  }
        }

        public override void comienza()
        {
            ui_principal.iniciado = true;
            this.subproceso = new Thread(new ThreadStart(leeArchivo));
            this.subproceso.IsBackground = true;
            this.subproceso.Start();
        }

        private void leeArchivo()
        {
            Delegate delegado;
            FileStream secuencia;
            BinaryReader lector;

            try
            {
                delegado = new SetItemListDelegate(insertaItem);
                secuencia = new FileStream(ruta_archivo, FileMode.Open);
                lector = new BinaryReader(secuencia);

                for (uint i = 0; i < n; i++)
                {
                    lb_datos.Invoke(delegado, new object[] { lector.ReadSingle() });
                    Thread.Sleep(1);
                }

                lector.Close();
            }
            catch (IOException ioex)
            {
                MessageBox.Show(ioex.Message);
            }

            ui_principal.terminado = true;
            ui_principal.iniciado = false;
        }
    }
}
