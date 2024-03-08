/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package shapespazourekondrej;

/**
 *
 * @author ondrejpazourek
 */
public class Circle extends Shape {
	protected double radius;
	
	public Circle(Point center, double average) {
		super(center);
		this.radius = average;
	}
	
	@Override
	public double getArea() {
		return Math.PI * Math.pow(radius, 2); 
	}

	@Override
	public double getDiameter() {
		return 2 * Math.PI * radius; 
	}
}
