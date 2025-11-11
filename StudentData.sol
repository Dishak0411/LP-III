    // SPDX-License-Identifier: MIT
    pragma solidity ^0.8.19;

    contract StudentData {
        // Structure to store student information
        struct Student {
            uint id;
            string name;
            uint age;
            string course;
        }

        // Dynamic array to store multiple students
        Student[] public students;

        // Owner of the contract
        address public owner;

        // Events for logs
        event StudentAdded(uint id, string name);
        event Received(address sender, uint amount);
        event FallbackCalled(address sender, uint amount, bytes data);

        // Constructor sets the deployer as the owner
        constructor() {
            owner = msg.sender;
        }

        // Modifier to restrict function access
        modifier onlyOwner() {
            require(msg.sender == owner, "Only owner can perform this action");
            _;
        }

        // Function to add a new student (only owner)
        function addStudent(uint _id, string memory _name, uint _age, string memory _course) public onlyOwner
        {
            Student memory newStudent = Student({
                id: _id,
                name: _name,
                age: _age,
                course: _course
            });
            students.push(newStudent);
            emit StudentAdded(_id, _name);
        }

        // Function to get total number of students
        function getTotalStudents() public view returns (uint) {
            return students.length;
        }

        // Function to get details of a student by index
        function getStudent(uint index) public view returns (uint, string memory, uint, string memory)
        {
            require(index < students.length, "Invalid index");
            Student memory s = students[index];
            return (s.id, s.name, s.age, s.course);
        }

        // Receive function (called when Ether sent without data)
        receive() external payable {
            emit Received(msg.sender, msg.value);
        }

        // Fallback function (called when unknown function or Ether sent)
        fallback() external payable {
            emit FallbackCalled(msg.sender, msg.value, msg.data);
        }
    }