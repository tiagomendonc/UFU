package exB;

public class Tempo {
	int hora, minuto, segundo;
	
	public Tempo(int hora, int minuto, int segundo) {
		if(hora < 0 || hora > 23) {
			this.hora = 0;
		} else {
			this.hora = hora;
		}
		
		if(minuto < 0 || minuto > 59) {
			this.minuto = 0;
		} else {
			this.minuto = minuto;
		}
		
		if(segundo < 0 || segundo > 59) {
			this.segundo = 0;
		} else {
			this.segundo = segundo; 
		}
	}
	
	public void mostraTempoHHMMSS() {
		System.out.println(hora+minuto+segundo);
	}
	
	public void mostraTempoAMPM() {
		if(hora >= 13) {
			System.out.println((hora - 12)+":"+minuto+":"+segundo+" PM");
		} else {
			System.out.println(hora+":"+minuto+":"+segundo+" AM");
		}
	}
	
	public void incrementaMinuto(int minuto) {
		if(this.minuto + minuto >= 60) {
			if(this.hora == 23) {
				this.hora = 0;
			} else {
				this.hora++;
			}
			this.minuto = 0;
		} else {
			this.minuto = minuto;
		}
	}
	
	public void decrementaMinuto(int minuto) {
		if(this.minuto - minuto <= 0) {
			if(this.hora == 0) {
				this.hora = 23;
			} else {
				this.hora--;
			}
			this.minuto = 59;
		} else {
			this.minuto = minuto;
		}
	}
}
