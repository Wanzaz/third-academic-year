/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package shapespazourekondrej;

import java.util.Random;

/**
 *
 * @author ondrejpazourek
 */
public class ShapesPazourekOndrej {

	public static void main(String[] args) {
        // Create an array of Shape objects
        Shape[] shapes = new Shape[10];

        // Populate the array with random shapes
        for (int i = 0; i < shapes.length; i++) {
            shapes[i] = getRandomShape();
        }

         // Calculate the sum of areas and perimeters using polymorphism
        double sumArea = 0;
        double sumDiameter = 0;

        for (Shape shape : shapes) {
            sumArea += shape.getArea();
            sumDiameter += shape.getDiameter();
        }

        // Print the results
        System.out.println("Sum of areas of all shapes: " + sumArea);
        System.out.println("Sum of perimeters of all shapes: " + sumDiameter);
    }

    // Method to generate a random Shape
	private static Shape getRandomShape() {
		Random random = new Random();
    
		// I don't know what to do with the coordinates
		int x = random.nextInt(61) + 20; // x-coordinate between 20 and 80
		int y = random.nextInt(61) + 20; // y-coordinate between 20 and 80
		Point center = new Point(x, y);

		// Randomly choose a shape type
		int shapeType = random.nextInt(3);

		switch (shapeType) {
			case 0:
				return new Rectangle(center, random.nextDouble() * 20, random.nextDouble() * 20);
			case 1:
				return new Circle(center, random.nextDouble() * 20);
			case 2:
				return new Triangle(center, random.nextDouble() * 20);
			default:
				// Log an error or throw an exception with a meaningful message
				throw new IllegalStateException("Unexpected shape type: " + shapeType);
		}
}
	
	
}
