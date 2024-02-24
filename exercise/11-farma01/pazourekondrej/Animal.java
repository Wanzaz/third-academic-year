/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package farma01.pazourekondrej;

/**
 *
 * @author ondrejpazourek
 */
public class Animal {

	protected String name;
	protected int numberOfLegs;

	public Animal(String name, int numberOfLegs) {
		this.name = name;
		this.numberOfLegs = numberOfLegs;
	}


	public int getNumberOfLegs() { return numberOfLegs; }
	public String getName() { return name; }
	
	public void setName(String name) { this.name = name; }
	public void setNumberOfLegs(int numberOfLegs) { 
		if (numberOfLegs > 0) {

		}
		this.numberOfLegs -= numberOfLegs;
	}
	
	@Override
	public String toString() {
		return name + " - " + numberOfLegs;
	}
	
	public void makeSound() { }
	
}
