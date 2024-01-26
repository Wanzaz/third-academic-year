/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package cary.pazourekondrej;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class CaryPazourekOndrej {

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            List<Point> points = readPoints(scanner);
            if (points.size() < 2) {
                System.out.println("Please enter at least two points.");
                return;
            }

            // Find the rectangle that contains all points
            Point topLeft = findTopLeft(points);
            Point bottomRight = findBottomRight(points);

            printRectangleCoordinates(topLeft, bottomRight);
        }
    }

    private static List<Point> readPoints(Scanner scanner) {
        List<Point> points = new ArrayList<>();
        System.out.println("Enter points with coordinates [x; y] format, separated by a semicolon and space: ");
        String input = scanner.nextLine();
        double[] coordinates = parseCoordinates(input);

        for (int i = 0; i < coordinates.length; i += 2) {
            points.add(new Point(coordinates[i], coordinates[i + 1]));
        }

        return points;
    }

    private static double[] parseCoordinates(String input) {
        String[] parts = input.replaceAll("[\\[\\];,]", "").split("\\s+");
        double[] coordinates = new double[parts.length];
        for (int i = 0; i < parts.length; i++) {
            coordinates[i] = Double.parseDouble(parts[i]);
        }
        return coordinates;
    }

    private static void printRectangleCoordinates(Point topLeft, Point bottomRight) {
        System.out.println("Rectangle coordinates:");
        System.out.println("Top-left corner: [" + topLeft.getX() + "; " + topLeft.getY() + "]");
        System.out.println("Bottom-right corner: [" + bottomRight.getX() + "; " + bottomRight.getY() + "]");
    }

    private static Point findTopLeft(List<Point> points) {
        double minX = points.get(0).getX();
        double minY = points.get(0).getY();

        for (Point point : points) {
            minX = Math.min(minX, point.getX());
            minY = Math.min(minY, point.getY());
        }

        return new Point(minX, minY);
    }

    private static Point findBottomRight(List<Point> points) {
        double maxX = points.get(0).getX();
        double maxY = points.get(0).getY();

        for (Point point : points) {
            maxX = Math.max(maxX, point.getX());
            maxY = Math.max(maxY, point.getY());
        }

        return new Point(maxX, maxY);
    }
}
