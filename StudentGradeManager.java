import java.util.ArrayList;
import java.util.Scanner;

class Student {
    String name;
    double grade;

    Student(String name, double grade) {
        this.name = name;
        this.grade = grade;
    }
}

public class StudentGradeManager {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<Student> students = new ArrayList<>();

        System.out.println("📘 Student Grade Manager");
        System.out.print("Enter number of students: ");
        int n = scanner.nextInt();
        scanner.nextLine();  // Clear input buffer

        // Input student data
        for (int i = 0; i < n; i++) {
            System.out.print("\nEnter name of student " + (i + 1) + ": ");
            String name = scanner.nextLine();

            System.out.print("Enter grade for " + name + ": ");
            double grade = scanner.nextDouble();
            scanner.nextLine(); // Clear input buffer

            students.add(new Student(name, grade));
        }

        // Calculate statistics
        double total = 0;
        double highest = Double.MIN_VALUE;
        double lowest = Double.MAX_VALUE;
        String topStudent = "";
        String lowStudent = "";

        for (Student s : students) {
            total += s.grade;
            if (s.grade > highest) {
                highest = s.grade;
                topStudent = s.name;
            }
            if (s.grade < lowest) {
                lowest = s.grade;
                lowStudent = s.name;
            }
        }

        double average = total / n;

        // Summary Report
        System.out.println("\n📊 Summary Report:");
        System.out.printf("Average Grade: %.2f\n", average);
        System.out.printf("Highest Grade: %.2f (%s)\n", highest, topStudent);
        System.out.printf("Lowest Grade: %.2f (%s)\n", lowest, lowStudent);

        System.out.println("\n📄 All Students:");
        for (Student s : students) {
            System.out.printf("→ %s: %.2f\n", s.name, s.grade);
        }

        scanner.close();
    }
}
