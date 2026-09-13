import java.util.*;
import java.io.*;

public class Retrovirus extends Doenca
{
    
    private static double r0 = 0.63;     
    
    public static void alterarR0(double r)
    {   r0=r;}
    
    public String nsintoma;
    public double threshold;
    private Hashtable<String,Integer>sintomas; 
    
    public Retrovirus(String nome, double probabilidadeinfecao)
    {
        super(nome,probabilidadeinfecao);
        this.sintomas = new Hashtable<String,Integer>();
    }
    
    public String nome()
    {   return super.getnome();}
    
    public double getR0()
    {   return this.r0;}
    
    public void gettempodeinfecao()
    {   System.out.println( "o tempo de infeção é: sempre");}
    
    public double getcapacidade(int mes)
    {
            return 0.0;
    }
    
    public boolean passou(GregorianCalendar teste){
        GregorianCalendar hoje = new GregorianCalendar();
        if(teste.get(GregorianCalendar.MONTH) == hoje.get(GregorianCalendar.MONTH)+1 && hoje.get(GregorianCalendar.DAY_OF_MONTH)-teste.get(GregorianCalendar.DAY_OF_MONTH)>=8)
            return true;
        else if(teste.get(GregorianCalendar.MONTH) == hoje.get(GregorianCalendar.MONTH) && hoje.get(GregorianCalendar.DAY_OF_MONTH)+30-teste.get(GregorianCalendar.MONTH)>=8)
            return true;
        else 
            return false;
    }
    
    
    
    public void adicionarsintomas(int probtosse, int probfebre, int probfebrealta, int probnauseas, int probdiarreia, int probcefaleias, int probdoresmusc, int probcansacoger, int probdifrespiratorias, int narizentupido, int probdoresgarganta, int probperdapalaouolfato, int probdorpeito, int probvomitos, int probespiros, int probolhoshumidos)
    {   
        this.sintomas.put("tosse seca",probtosse);
        this.sintomas.put("febre",probfebre);
        this.sintomas.put("febre alta",probfebrealta);
        this.sintomas.put("nauseas",probnauseas);
        this.sintomas.put("diarreia",probdiarreia);
        this.sintomas.put("cefaleias",probcefaleias);
        this.sintomas.put("dores musculares",probdoresmusc);
        this.sintomas.put("cancaso geral",probcansacoger);
        this.sintomas.put("dificuldades respiratorias",probdifrespiratorias);
        this.sintomas.put("nariz entupido",narizentupido);
        this.sintomas.put("dores de garganta",probdoresgarganta);
        this.sintomas.put("perdad de paladar ou olfato",probperdapalaouolfato);
        this.sintomas.put("dor no peito",probdorpeito);
        this.sintomas.put("vomitos",probvomitos);
        this.sintomas.put("espirros",probespiros);
        this.sintomas.put("olhos humidos",probolhoshumidos);
    }
    
    public Hashtable<String,Integer> getsintomas()
    {        
        return sintomas;
    }
    
     public Retrovirus clone(int mes)
    {
        Retrovirus r = new Retrovirus(this.getnome(), this.getprobinfecao(mes));
        for(Integer i : this.sintomas.values())
            r.getsintomas();
        return r;
    } 
}
