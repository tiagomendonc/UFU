/*
 * Neste projeto é utilizado Singleton para a corstrução dos fabricantes e Fábrica para a construção dos celulares.
 * É importante utilizar estes dois padrões pois:
 * 	- o padrão Singleton garante que uma única instância de uma classe seja mantida e comparilhada.
 * 	- o padrãio Fábrica cria objetos de maneira flexível, ocultando a complexidade da criação.
 */


package celulares;

public class Main {  
	public static void main(String [] args ) {
        FabricanteCelular apple = FabricanteCelularSingleton.getInstance("apple");
        Celular iphones = apple.constroiCelular("iphones");
        
        iphones.tiraFoto();
        iphones.fazLigacao();
        System.out.println("Iphone S rodando normalmente");

        FabricanteCelular samsung = FabricanteCelularSingleton.getInstance("samsung");
        Celular galaxy8 = samsung.constroiCelular("galaxy8");
        
        galaxy8.tiraFoto();
        galaxy8.fazLigacao();
        System.out.println("Galaxy8 rodando normalmente");        
    }    
}
