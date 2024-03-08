/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package shapespazourekondrej;

/**
 *
 * @author ondrejpazourek
 */
public class Triangle extends Shape {
	protected double side;
	
	public Triangle(Point center, double side) {
		super(center);
		this.side = side;
	}

	@Override
	public double getArea() {
		double semiPerimeter = getDiameter() / 2;
        return Math.sqrt(semiPerimeter * (semiPerimeter - side) * (semiPerimeter - side) * (semiPerimeter - side)); 
	}

	@Override
	public double getDiameter() {
		return 3 * side;
	}
}
