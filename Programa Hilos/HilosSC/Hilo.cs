using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Windows.Forms;
using System.IO;

namespace HilosSC
{
    class Hilo
    {
        public static uint n;
        public static Hilos_UI ui_principal;

        public delegate void SetItemListDelegate(float valor);
        public Thread subproceso;
        public ListBox lb_datos;

        public Hilo(ListBox lb_datos)
        {
            this.lb_datos = lb_datos;
        }

        public uint dameNumeroDatos()
        {
            return n;
        }

        public virtual void comienza()
        {
            
        }

        public void suspende()
        {
            if (subproceso.IsAlive)
            {
                ui_principal.pausado = true;
                subproceso.Suspend();
            }
        }

        public void aborta()
        {
            if (subproceso.IsAlive)
            {
                ui_principal.terminado = true;
                ui_principal.iniciado = false;
                subproceso.Resume();
                subproceso.Abort();
            }
        }

        public void continua()
        {
            if (subproceso.IsAlive)
            {
                ui_principal.pausado = false;
                subproceso.Resume();
            }
        }

        public void insertaItem(float valor)
        {
            lb_datos.Items.Add(valor);
            lb_datos.SelectedIndex = lb_datos.Items.Count - 1;
        }
    }
}
