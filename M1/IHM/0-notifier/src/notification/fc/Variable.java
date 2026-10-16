/* notification.Variable
 * (c) blanch@imag.fr 2025-                                                */


package notification.fc;

import static java.lang.Math.random;


public class Variable extends Thread {
	double value = 0.;
	
	public Variable() {
		start();
	}
	
	public void run() {
		while(true) {
			double v = getValue();
			if(random() > .5) {
				v += random();
			} else {
				v -= random();
			}
			setValue(v);
			try {
				sleep((long)(1000*random()));
			} catch(InterruptedException e) {
				break;
			}
		}
	}
	
	public double getValue() { return value; }
	public void setValue(double new_value) {
		value = new_value;
		System.err.print("Variable: ");
		System.err.println(value);
		
	}
}
