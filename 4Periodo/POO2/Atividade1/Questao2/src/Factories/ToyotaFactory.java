package Factories;

import app.GenericVehicle;
import Interfaces.IVehicle;
import Interfaces.IVehicleMaker;

public class ToyotaFactory implements IVehicleMaker {
	public IVehicle makeVehicle(String modelo) {
		switch (modelo) {
		case "Corolla":
			return new GenericVehicle();
		case "Hilux":
			return new GenericVehicle();
		case "Etios":
			return new GenericVehicle();
		default:
			throw new IllegalArgumentException("Modelo nao existente");
		}
	}
}
