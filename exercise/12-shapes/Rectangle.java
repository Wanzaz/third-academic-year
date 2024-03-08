/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package shapespazourekondrej;

/**
 *
 * @author ondrejpazourek
 */
public class Rectangle extends Shape {
	protected double height;
	protected double width;
	
	public Rectangle(Point center, double height, double width) {
		super(center);
		this.height = height;
		this.width = width;
	}
	
	@Override
	public double getArea() {
		return height * width; 
	}

	@Override
	public double getDiameter() {
		return 2 * (height + width);
	}
	
}
