import java.util.*;
import java.lang.*;

public class Menu
{

    public static void main(String a[])
    {
        Coronavirus coronav1 = new Coronavirus("Coronavirus",100);
        Sistemadesaude sns = new Sistemadesaude();
        Pessoa p1 = new Pessoa("AAA",001,23,07,2000);
        Pessoa p2 = new Pessoa("BBB",002,02,02,2002);
        Pessoa p3 = new Pessoa("CCC",003,20,10,1970);
        Contacto c1 = new Contacto(1,1);
        //p1.nova_doenca(coronav1,19,1,2021);
        Scanner in = new Scanner(System.in);
        int n1 = -1;
        while(n1 != 0)
        {
            System.out.println("1 - Adicionar pessoa");
            System.out.println("2 - Ver pessoas");
            System.out.println("3 - Adicionar doença a pessoa");
            System.out.println("4 - Ver doenças numa pessoa");
            System.out.println("0 - Exit");
            System.out.println();
            n1 = in.nextInt();
            switch(n1)
            {
                case 1:
                {   
                    System.out.println("Abriu ´Adicionar pessoa´ ");

                    break; 
                }
                case 2: 
                {   
                    System.out.println("Abriu ´Ver pessoas´ "); 
                    break; 
                }
                case 3:
                {   
                    System.out.println("Abriu ´Adicionar doença a pessoa´ ");
                    Scanner Tdia = new Scanner(System.in);
                    p1.nova_doenca(doenca d, Tdia, Tmes,int Tano,int mes);
                    break;
                }
                case 4:
                {   
                    System.out.println("Abriu ´Ver doenças numa pessoa´ "); 
                    break; 
                }
                case 0: //EXIT FUNCTION
                {
                    System.out.println("FECHANDO...");
                    //GUARDAR EM FICHEIRO
                    System.out.println("EXIT COMPLETE!!");
                    System.exit(0);
                }
                default:
                {
                    System.out.println("Erro.. não existe essa opção."); 
                    break;
                }   
            }   
        }
    }

}