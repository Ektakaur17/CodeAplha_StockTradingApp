import java.io.*;
import java.util.*;

class Stock {
    String symbol;
    String name;
    double price;

    public Stock(String symbol, String name, double price) {
        this.symbol = symbol;
        this.name = name;
        this.price = price;
    }

    public void updatePrice() {
        double change = (Math.random() * 0.1) - 0.05; // +/-5%
        price = Math.round((price * (1 + change)) * 100.0) / 100.0;
    }
}

class Market {
    Map<String, Stock> stocks = new HashMap<>();

    public Market() {
        stocks.put("AAPL", new Stock("AAPL", "Apple Inc.", 180.00));
        stocks.put("GOOG", new Stock("GOOG", "Alphabet Inc.", 2700.00));
        stocks.put("TSLA", new Stock("TSLA", "Tesla Inc.", 800.00));
        stocks.put("AMZN", new Stock("AMZN", "Amazon.com Inc.", 3400.00));
    }

    public void displayMarket() {
        System.out.println("\n📈 Market Data:");
        for (Stock stock : stocks.values()) {
            stock.updatePrice();
            System.out.println(stock.symbol + " - " + stock.name + " | Price: $" + stock.price);
        }
    }

    public Stock getStock(String symbol) {
        return stocks.get(symbol.toUpperCase());
    }
}

class User {
    String username;
    double balance;
    Map<String, Integer> portfolio;

    public User(String username) {
        this.username = username;
        this.balance = 10000.00;
        this.portfolio = new HashMap<>();
        loadPortfolio();
    }

    public void buyStock(Stock stock, int quantity) {
        double total = stock.price * quantity;
        if (balance >= total) {
            balance -= total;
            portfolio.put(stock.symbol, portfolio.getOrDefault(stock.symbol, 0) + quantity);
            System.out.println("✅ Bought " + quantity + " shares of " + stock.symbol + " at $" + stock.price);
        } else {
            System.out.println("❌ Insufficient balance.");
        }
    }

    public void sellStock(Stock stock, int quantity) {
        int owned = portfolio.getOrDefault(stock.symbol, 0);
        if (owned >= quantity) {
            balance += stock.price * quantity;
            portfolio.put(stock.symbol, owned - quantity);
            if (portfolio.get(stock.symbol) == 0) portfolio.remove(stock.symbol);
            System.out.println("✅ Sold " + quantity + " shares of " + stock.symbol + " at $" + stock.price);
        } else {
            System.out.println("❌ Not enough shares to sell.");
        }
    }

    public void viewPortfolio(Market market) {
        System.out.println("\n👤 Portfolio of " + username);
        System.out.printf("💰 Balance: $%.2f\n", balance);
        System.out.println("📊 Holdings:");
        double totalValue = 0;
        for (String symbol : portfolio.keySet()) {
            int qty = portfolio.get(symbol);
            Stock stock = market.getStock(symbol);
            if (stock != null) {
                double value = stock.price * qty;
                totalValue += value;
                System.out.printf("  %s - %d shares @ $%.2f = $%.2f\n", symbol, qty, stock.price, value);
            }
        }
        System.out.printf("📈 Total Portfolio Value: $%.2f\n", (balance + totalValue));
    }

    public void savePortfolio() {
        try {
            PrintWriter writer = new PrintWriter(username + "_portfolio.txt");
            writer.println(balance);
            for (String symbol : portfolio.keySet()) {
                writer.println(symbol + ":" + portfolio.get(symbol));
            }
            writer.close();
        } catch (IOException e) {
            System.out.println("❌ Failed to save portfolio.");
        }
    }

    public void loadPortfolio() {
        try {
            File file = new File(username + "_portfolio.txt");
            if (file.exists()) {
                Scanner scanner = new Scanner(file);
                if (scanner.hasNextDouble()) {
                    balance = scanner.nextDouble();
                }
                scanner.nextLine();
                while (scanner.hasNextLine()) {
                    String line = scanner.nextLine();
                    String[] parts = line.split(":");
                    if (parts.length == 2) {
                        portfolio.put(parts[0], Integer.parseInt(parts[1]));
                    }
                }
                scanner.close();
            }
        } catch (Exception e) {
            System.out.println("❌ Failed to load portfolio.");
        }
    }
}

public class StockTradingApp {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Market market = new Market();

        System.out.print("Enter your username: ");
        String username = sc.nextLine();
        User user = new User(username);

        while (true) {
            System.out.println("\n--- STOCK TRADING MENU ---");
            System.out.println("1. View Market");
            System.out.println("2. Buy Stock");
            System.out.println("3. Sell Stock");
            System.out.println("4. View Portfolio");
            System.out.println("5. Exit");
            System.out.print("Choose an option: ");
            String choice = sc.nextLine();

            switch (choice) {
                case "1":
                    market.displayMarket();
                    break;
                case "2":
                    System.out.print("Enter stock symbol to buy: ");
                    String buySymbol = sc.nextLine();
                    System.out.print("Enter quantity: ");
                    int buyQty = sc.nextInt();
                    sc.nextLine();
                    Stock buyStock = market.getStock(buySymbol);
                    if (buyStock != null) {
                        buyStock.updatePrice();
                        user.buyStock(buyStock, buyQty);
                    } else {
                        System.out.println("❌ Invalid stock symbol.");
                    }
                    break;
                case "3":
                    System.out.print("Enter stock symbol to sell: ");
                    String sellSymbol = sc.nextLine();
                    System.out.print("Enter quantity: ");
                    int sellQty = sc.nextInt();
                    sc.nextLine();
                    Stock sellStock = market.getStock(sellSymbol);
                    if (sellStock != null) {
                        sellStock.updatePrice();
                        user.sellStock(sellStock, sellQty);
                    } else {
                        System.out.println("❌ Invalid stock symbol.");
                    }
                    break;
                case "4":
                    user.viewPortfolio(market);
                    break;
                case "5":
                    user.savePortfolio();
                    System.out.println("👋 Portfolio saved. Goodbye!");
                    return;
                default:
                    System.out.println("❌ Invalid choice. Try again.");
            }
        }
    }
}
