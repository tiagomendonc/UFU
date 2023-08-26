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
