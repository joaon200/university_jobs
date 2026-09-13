import java.util.*;
import java.io.*;

public class Pessoa
{
    private String nome;
    private int codigo;
    private GregorianCalendar dataNasc;
    private GregorianCalendar data;
    private GregorianCalendar dataUTP; //data do último teste positivo 
    private Hashtable <GregorianCalendar , Doenca> listaVirus = new Hashtable<GregorianCalendar , Doenca>(); //lista de virus
    private ArrayList<String> listaSintomas; //lista de sintomas
    private int threshold; //criar de forma a variar com a idade
    private double capinfetar;
    private double probaocorrer;
    private Hashtable <String,Contacto> listaContactos = new Hashtable<String,Contacto>(); //hashtable de contactos
    private GregorianCalendar temp;
    
    public Pessoa(String n, int cod, int Ndia, int Nmes, int Nano)
    {
        this.nome = n;
        this.codigo = cod;
        this.dataNasc = new GregorianCalendar(Nano,Nmes,Ndia);
        this.listaSintomas = new ArrayList<String>();
        this.threshold = threshold();
        this.capinfetar = capinfetar();
        this.probaocorrer=0;
    }
    
    public String getNome()
    { return this.nome;}
    
    public int codigo()
    { return this.codigo;}
    
    public double getprobtransmicao(Doenca d, int mes)
    {
        return d.getprobinfecao(mes)*this.capinfetar/100;
    }
    
    public GregorianCalendar getDataNasc()
    {
        System.out.printf("%d,%d,%d",this.dataNasc.get(Calendar.DAY_OF_MONTH),this.dataNasc.get(Calendar.MONTH),this.dataNasc.get(Calendar.YEAR));
        return this.dataNasc;
    }
    
    public GregorianCalendar getDataUTP()
    {
        System.out.printf("%d,%d,%d",this.dataUTP.get(Calendar.DAY_OF_MONTH),this.dataUTP.get(Calendar.MONTH),this.dataUTP.get(Calendar.YEAR));
        return this.dataUTP;
    }
    
    public ArrayList<String> /*void*/ getsintomas(Doenca d)
    {
        //Hashtable<String,Integer>sintomas = new Hashtable<String,Integer>();
        this.listaSintomas.clear();
        for(Doenca c: this.listaVirus.values())
        {
           //sintomas = d.getsintomas();
           Hashtable<String,Integer>sintomas = d.getsintomas();
           for(String i:sintomas.keySet())
           {
                if(sintomas.get(i)/threshold>=1.0)
                    this.listaSintomas.add(i);
                }
        }
        
        System.out.println(this.listaSintomas);
        return listaSintomas;
    }
    
    public boolean hosp(Doenca d)
    {
        if (getsintomas(d).contains("febre alta")||getsintomas(d).contains("dor no peito")||getsintomas(d).contains("dificuldades respiratorias"))
            return true;
        else 
            return false;
    }
    
    public int getthreshold()
    {return this.threshold;}
    private int threshold()
    {
       if(idade()<=30)
            threshold = 92;
       else if(idade()>30 && idade()<=60)
            threshold = 60;
       else if(idade()>60)
            threshold = 50;
            
       return this.threshold;
    }
    
    public double getcapinfetar()
    {return this.capinfetar;}
    private double capinfetar()
    {
        if(idade()<=30)
            capinfetar = 85.0;
        else if(idade()>30 && idade()<=60)
            capinfetar = 70.0;
        else if(idade()>60)
            capinfetar = 50.0;
            
       return this.capinfetar;
    }
    
    public int idade()
    {
        GregorianCalendar hoje = new GregorianCalendar();
        int x = hoje.get(GregorianCalendar.YEAR) - dataNasc.get(GregorianCalendar.YEAR);
        
        if(dataNasc.get(GregorianCalendar.MONTH) > hoje.get(GregorianCalendar.MONTH)+1 || dataNasc.get(Calendar.MONTH) == hoje.get(GregorianCalendar.MONTH)+1 && dataNasc.get(GregorianCalendar.DAY_OF_MONTH) > hoje.get(GregorianCalendar.DAY_OF_MONTH))
        {   x=x-1;
            return x;}
        else 
        {   return x;}
    }
    
    public void nova_doenca(Doenca d,int Tdia , int Tmes, int Tano)
    {
        if (this.listaVirus.containsValue(d))
            System.out.println("ja tem este virus");
        else                                   
            this.listaVirus.put(this.dataUTP = new GregorianCalendar(Tano,Tmes,Tdia) , d.clone(Tmes));   
    }
    
    public void doencacontacto(Doenca d,Pessoa p,int mes)
    {
        this.listaVirus.put(p.getDataUTP(),d.clone(mes));
    }
    
    public Hashtable<GregorianCalendar,Doenca> getvirus()
    {
        for(GregorianCalendar d:listaVirus.keySet())
            if(listaVirus.get(d).passou(d))
                listaVirus.remove(d);
            
            
        
        //for(doenca d: listaVirus.values())
            //System.out.println(d.getsintomas());
        return this.listaVirus;
    }
    
    public void addcontacto(Pessoa p, Contacto c)
    {
        if(this.listaContactos.containsKey(p.getNome()))
            System.out.println("contacto ja adicionado");
        else
            this.listaContactos.put(p.getNome(),c.clone());
    }
    
    public Hashtable<String,Contacto> getcontactos()
    {
        return this.listaContactos;
    }
    
}
