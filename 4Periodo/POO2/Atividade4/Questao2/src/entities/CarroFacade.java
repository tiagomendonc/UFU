package entities;

public class CarroFacade {
	private Motor motor;
	private CintoDeSeguranca cinto;
	private Porta porta;
	private Farol farol;
	private Radio radio;
	
	public CarroFacade() {
		this.motor = new Motor();
		this.cinto = new CintoDeSeguranca();
		this.porta = new Porta();
		this.farol = new Farol();
		this.radio = new Radio();
	}
	
	public void iniciarCorrida() {
		motor.ligar();
		porta.trancar();
		cinto.travar();
		farol.acender();
		radio.ligar();
		radio.sintonizarEstacao("Minha estação preferida");
	}
	
	public void finalizarCorrida() {
		motor.desligar();
		porta.destrancar();
		cinto.destravar();
		farol.apagar();
		radio.desligar();
	}
}
