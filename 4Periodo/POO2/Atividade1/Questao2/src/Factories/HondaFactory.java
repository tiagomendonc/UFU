package Factories;

import app.GenericVehicle;
import Interfaces.IVehicle;
import Interfaces.IVehicleMaker;

public class HondaFactory implements IVehicleMaker {
	public IVehicle makeVehicle(String modelo) {
		switch(modelo) {
		case "City":
			return new GenericVehicle();
		case "Civic":
			return new GenericVehicle();
		case "Fit":
			return new GenericVehicle();
		default:
			throw new IllegalArgumentException("Modelo não encontrado");
		}
	}
}
