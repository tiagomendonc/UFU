package celulares;

public class Apple implements FabricanteCelular {
	@Override
	public Celular constroiCelular(String modelo) {
		if(modelo.equals("iphones")) {
			return new IphoneS();
		}
		
		return null;
	}
}
