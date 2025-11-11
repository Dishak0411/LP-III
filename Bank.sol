// SPDX-License-Identifier: MIT
pragma solidity ^0.8.19;

contract Bank {
    
    event Deposit(uint256 amount);
    event Withdraw(uint256 amount);

    uint256 private balance;

    constructor() {
        balance = 0;
    }

    // Deposit function
    function deposit() public payable {
        require(msg.value > 0, "Deposit amount must be greater than 0");
        balance += msg.value;
        emit Deposit(msg.value);
    }

    // Withdraw function
    function withdraw(uint amount) public {
        require(amount <= balance, "Insufficient balance");
        balance -= amount;
        payable(msg.sender).transfer(amount);
        emit Withdraw(amount);
    }

    // Show balance
    function getBalance() public view returns (uint) {
        return balance;
    }
}