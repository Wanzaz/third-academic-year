/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package farma01.pazourekondrej;

/**
 *
 * @author ondrejpazourek
 */
public class Dog extends Animal {

	protected String race;
	protected int age;

	public Dog(String name, String race, int age) {
		super(name, 4);
		this.age = age;
		this.race = race;
	}
	
	public Dog(String name, String race) {
		super(name, 4);
		this.age = 0;
		this.race = race;
	}
	
	public Dog(String race) {
		super("NoName", 4);
		this.age = 0;
		this.race = race;
	}

	
	public String getRace() { return race; }
	public int getAge() { return age; }

	public void setAge(int age) {
		if (age > this.age) {
			this.age = age;
		}
	}
	
	@Override
	public String toString() {
		return name + " - " + numberOfLegs;
	}

	@Override
	public void makeSound() {
		System.out.println("Huf huf");
	}
}
