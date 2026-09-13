import java.util.*;
import java.io.*;

public class Sistemadesaude
{
    private int numeroinfetados;
    private ArrayList<Pessoa> pessoas = new ArrayList<Pessoa>();
    private ArrayList<Pessoa>hospitalizados = new ArrayList<Pessoa>();
    
    public Sistemadesaude()
    {
        
    }
   
    public void addPessoa(Pessoa p)
    {
        if(this.pessoas.contains(p))
            System.out.println("pessoa ja existente");
        else if(p != null)
            this.pessoas.add(p);
        }
        
    public ArrayList<Pessoa> getpessoas()
    {
        System.out.println(this.pessoas);
        return this.pessoas;
    }
    
    public ArrayList<Pessoa> hospitalizados_por_doenca(Doenca d)
    {
        this.hospitalizados.clear();
        for(Pessoa p : this.pessoas)        
            if(p.hosp(d)) 
                this.hospitalizados.add(p);
                
        return this.hospitalizados;
    }
    
    public int infetados_por_doenca(Doenca d)
    {
        numeroinfetados=0;
        Hashtable<GregorianCalendar , Doenca> listaVirusc = new Hashtable<GregorianCalendar, Doenca>();
        for(Pessoa p : this.pessoas)
            { 
                listaVirusc.clear();
                listaVirusc = p.getvirus();   
                if(p.getvirus().containsValue(d));
                    numeroinfetados ++;
            }
        return numeroinfetados;
    }
    
    public void prop_doenca(Doenca d, int mes)
    {
        Hashtable<String,Contacto>lista = new Hashtable<String,Contacto>();
        Hashtable<GregorianCalendar , Doenca> listaVirusc = new Hashtable<GregorianCalendar, Doenca>();
        Hashtable<GregorianCalendar , Doenca> listaVirust = new Hashtable<GregorianCalendar, Doenca>();
        
        for (Pessoa p : this.pessoas)
        {   
            listaVirusc.clear();
            listaVirust.clear();
            lista.clear();
            listaVirusc = p.getvirus();
            if(listaVirusc.containsValue(d))
            {
                lista = p.getcontactos();
            
                for(String s : lista.keySet())
                {
                    for (Pessoa t : this.pessoas)
                    {
                        listaVirust.clear();
                        listaVirust = t.getvirus();
                        if(lista.containsKey(t.getNome()))
                        {
                            if(p.getprobtransmicao(d,mes)>=t.getthreshold())
                            {
                                if(listaVirust.containsValue(d))
                                    {}
                                else
                                    {t.doencacontacto(d,p,mes);}
                            }
                        }
                    }
                }
             } 
        }
    }
            
                
            
    
}
