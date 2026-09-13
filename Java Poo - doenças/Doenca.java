import java.util.*;
import java.io.*;

public abstract class Doenca
{
   private String nome;
   private double probinfect;
   
    public Doenca(String nome, double probabilidadeinfecao )
    {
        this.nome = nome;
        this.probinfect = probabilidadeinfecao;
    }
    
    public String getnome()
    { return this.nome;}
    
    public double getprobinfecao(int mes)
    {
        double parc = 0.0;
        parc=this.probinfect * getcapacidade(mes);
        return this.probinfect + parc;
    }
    
    /*public String getinfodoenca()
    { return this.nome + "; " + this.probinfect + "; " + getcapacidade() + "; ";} */
    public abstract boolean passou(GregorianCalendar teste);
    public abstract Hashtable<String,Integer> getsintomas();
    public abstract double getcapacidade(int mes);
    public abstract Doenca clone(int mes);
}