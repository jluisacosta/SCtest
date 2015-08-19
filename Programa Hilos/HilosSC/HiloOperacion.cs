using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Threading;

namespace HilosSC
{
    class HiloOperacion:Hilo
    {
        private ListBox lb_arch1;
        private ListBox lb_arch2;

        public HiloOperacion(ListBox lb_resultado,ListBox lb_arch1,ListBox lb_arch2):base(lb_resultado)
        {
            this.lb_arch1 = lb_arch1;
            this.lb_arch2 = lb_arch2;
        }

        public override void comienza()
        {
            ui_principal.iniciado = true;
            this.subproceso = new Thread(new ThreadStart(aplicaFormula));
            this.subproceso.IsBackground = true;
            this.subproceso.Start();
        }

        private void aplicaFormula()
        {
            Delegate delegado = new SetItemListDelegate(insertaItem);
            float resultado;
            int i=1;

            while (i <= n)
            {
                if (lb_arch1.Items.Count>=i && lb_arch2.Items.Count>=i)
                {
                    //Fómula del teorema de Pitágoras
                    resultado = (float)Math.Sqrt(Math.Pow(Convert.ToDouble(lb_arch1.Items[i-1]), 2) 
                                + Math.Pow(Convert.ToDouble(lb_arch2.Items[i-1]), 2));
                    lb_datos.Invoke(delegado, new object[] { resultado });
                    i++;
                    Thread.Sleep(1);    //Cambio de contexto
                }
            }

            ui_principal.terminado = true;
            ui_principal.iniciado = false;
        }
    }
}
