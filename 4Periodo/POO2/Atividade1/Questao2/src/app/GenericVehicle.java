package app;

import Interfaces.IVehicle;

public class GenericVehicle implements IVehicle {
	@Override
	public void start() {
		System.out.println("started");
	}
	
	@Override
	public void drive() {
		System.out.println("moving");
	}
	
	@Override
	public void stop() {
		System.out.println("stopped");
	}
}
