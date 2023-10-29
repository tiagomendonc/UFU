package entities;

import interfaces.*;

public abstract class Veiculo {
	abstract void accept(Visitor visitor);
}
