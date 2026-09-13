import java.util.*;
import java.io.*;
public class Coronavirus extends Doenca
{
     private static double r0 = 0.9;
    private static int tempoinfecao =14;
    
    public static void alterarR0(double r)
    {   r0=r;    }
    public static void alterartempoinfecao(int tempinfecao) 
    {   tempoinfecao=tempinfecao;    }
    
    public String nsintoma;
    public double threshold;
    private Hashtable<String, Integer>sintomas; 
    
    public Coronavirus(String nome, double probabilidadeinfecao)
    {
        super(nome,probabilidadeinfecao);
        this.sintomas = new Hashtable<String,Integer>();
    }
    
    public String nome()
    {
        return super.getnome(); 
    }
    
    public double getR0()
    {   return this.r0;}
    
    public int gettempodeinfecao()
    {   return this.tempoinfecao;}
    
    public double getcapacidade(int mes)
    {
        if(mes == 11 || mes==12 || mes==1 || mes==2)
            return 0.25;
        else 
            return 0.0;
    }
    
    public boolean passou(GregorianCalendar teste){
        GregorianCalendar hoje = new GregorianCalendar();
        if(teste.get(GregorianCalendar.MONTH) == hoje.get(GregorianCalendar.MONTH)+1 && hoje.get(GregorianCalendar.DAY_OF_MONTH)-teste.get(GregorianCalendar.DAY_OF_MONTH)>=14)
            return true;
        else if(teste.get(GregorianCalendar.MONTH) == hoje.get(GregorianCalendar.MONTH) && hoje.get(GregorianCalendar.DAY_OF_MONTH)+30-teste.get(GregorianCalendar.MONTH)>=14)
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
        this.sintomas.put("perda de paladar ou olfato",probperdapalaouolfato);
        this.sintomas.put("dor no peito",probdorpeito);
        this.sintomas.put("vomitos",probvomitos);
        this.sintomas.put("espirros",probespiros);
        this.sintomas.put("olhos humidos",probolhoshumidos);
    }
    
    public Hashtable<String,Integer> getsintomas()
    {        
        return sintomas;
    }
    
    public Coronavirus clone(int mes)
    {
        Coronavirus c = new Coronavirus(super.getnome(), super.getprobinfecao(mes));
        for(Integer i : this.sintomas.values())
            c.getsintomas();
        return c;
    }  

}
