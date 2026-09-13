import java.util.*;
import java.io.*;

public class Contacto
{
    private double x,y;
    private GregorianCalendar datacontacto;
    
    public Contacto(double coordenadax, double coordenaday)
    {
       this.x=coordenadax;
       this.y=coordenaday;
       
    }
    
    public void adddata( int dia, int mes, int ano)
    {   this.datacontacto = new GregorianCalendar(ano,mes,dia);}
    
    public double getx()
    {
        return this.x;
    }
    
    public double gety()
    {
        return this.y;
    }
    
    public GregorianCalendar getdatacontacto()
    {
        //System.out.printf("%d,%d,%d",this.datacontacto.get(Calendar.DAY_OF_MONTH),this.datacontacto.get(Calendar.MONTH),this.datacontacto.get(Calendar.YEAR));
        return this.datacontacto;
    }
    
    public Contacto clone()
    {
        Contacto c = new Contacto(this.x,this.y);
        c.getdatacontacto();
        return c;
    }
}
