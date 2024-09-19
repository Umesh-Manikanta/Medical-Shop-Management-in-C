# 🏥 Friends Pharmacy Management System

## 📋 Project Overview

Welcome to the **Friends Pharmacy Management System**! This C program is designed to streamline pharmacy operations, featuring user authentication, stock management, and billing functionalities. 

## 🚀 Features

- **🔐 User Authentication**: Secure login for accessing the system.
- **💊 Medicine Stock Management**: Check availability and manage inventory.
- **➕ Stock Addition**: Add new quantities to the existing stock.
- **🧾 Billing System**: Generate and print detailed billing statements.

## 📂 File Structure

- **`main.c`**: Contains the main logic of the application.
  - **Login System**: `checking()` function.
  - **Stock Management**: `stock_checking()` and `adding()` functions.
  - **Billing**: `billing()` function.
- **`MEDICINE_LIST.csv`**: CSV file for storing medicine data (`quantity,price,name`).

## 📜 Function Details

### `checking()`
- **Purpose**: Authenticate users by checking their credentials.
- **Features**:
  - User login with username and password validation.
  - Option to retry or exit on failure.

![Login Function](https://via.placeholder.com/600x300?text=Login+Function)

### `stock_checking()`
- **Purpose**: View the current stock of medicines.
- **Features**:
  - Display available quantities or indicate if a medicine is not found.
  
![Stock Checking](https://via.placeholder.com/600x300?text=Stock+Checking)

### `adding()`
- **Purpose**: Add new stock quantities.
- **Features**:
  - Update the inventory with new quantities.
  - Reflect changes in the CSV file.

![Add Stock](https://via.placeholder.com/600x300?text=Add+Stock)

### `billing()`
- **Purpose**: Generate a billing statement for prescriptions.
- **Features**:
  - Calculate total amount based on the prescription.
  - Print and display the bill.

![Billing Function](https://via.placeholder.com/600x300?text=Billing+Function)

## 🛠 How to Compile and Run

1. **Clone the Repository**

   ```bash
   git clone https://github.com/yourusername/pharmacy-management-system.git
