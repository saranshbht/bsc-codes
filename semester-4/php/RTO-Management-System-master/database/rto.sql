-- phpMyAdmin SQL Dump
-- version 4.8.5
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Apr 18, 2019 at 07:44 AM
-- Server version: 10.1.38-MariaDB
-- PHP Version: 7.1.27

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `rto`
--

-- --------------------------------------------------------

--
-- Table structure for table `admin`
--

CREATE TABLE `admin` (
  `username` varchar(20) NOT NULL,
  `password` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32;

--
-- Dumping data for table `admin`
--

INSERT INTO `admin` (`username`, `password`) VALUES
('admin', 'admin');

-- --------------------------------------------------------

--
-- Table structure for table `dl`
--

CREATE TABLE `dl` (
  `dlno` int(10) NOT NULL,
  `name` varchar(30) NOT NULL,
  `fatherName` varchar(30) NOT NULL,
  `dob` date NOT NULL,
  `bloodGroup` varchar(3) NOT NULL,
  `address` text NOT NULL,
  `aadhar` int(10) NOT NULL,
  `gender` varchar(2) NOT NULL,
  `mobileNumber` int(10) NOT NULL,
  `email` varchar(30) NOT NULL,
  `rto` varchar(30) NOT NULL,
  `status` int(1) NOT NULL,
  `id` int(10) NOT NULL,
  `validity` date NOT NULL,
  `issueDate` date NOT NULL,
  `examDate` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32;

--
-- Dumping data for table `dl`
--

INSERT INTO `dl` (`dlno`, `name`, `fatherName`, `dob`, `bloodGroup`, `address`, `aadhar`, `gender`, `mobileNumber`, `email`, `rto`, `status`, `id`, `validity`, `issueDate`, `examDate`) VALUES
(1234567890, 'Himanshu', 'Vikram Singh', '1999-12-24', 'B+', 'House', 1234567890, 'M', 1234567890, 'h@gmail.com', 'bh', 1, 1, '2019-04-30', '2019-04-02', '2019-04-25');

-- --------------------------------------------------------

--
-- Table structure for table `ll`
--

CREATE TABLE `ll` (
  `llno` int(10) NOT NULL,
  `name` varchar(30) NOT NULL,
  `fatherName` varchar(30) NOT NULL,
  `dob` date NOT NULL,
  `bloodGroup` varchar(3) NOT NULL,
  `address` text NOT NULL,
  `aadhar` int(10) NOT NULL,
  `gender` varchar(2) NOT NULL,
  `mobileNumber` int(10) NOT NULL,
  `email` varchar(30) NOT NULL,
  `rto` varchar(30) NOT NULL,
  `status` int(1) NOT NULL,
  `id` int(10) NOT NULL,
  `validity` date NOT NULL,
  `issueDate` date NOT NULL,
  `examDate` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32;

--
-- Dumping data for table `ll`
--

INSERT INTO `ll` (`llno`, `name`, `fatherName`, `dob`, `bloodGroup`, `address`, `aadhar`, `gender`, `mobileNumber`, `email`, `rto`, `status`, `id`, `validity`, `issueDate`, `examDate`) VALUES
(101, 'Himanshu', 'Vikram Singh', '1999-12-24', 'B+', 'House', 1234567890, 'M', 2147483647, 'himanshu@gmail.com', 'Bahadurgarh', 0, 1, '2019-04-17', '2019-04-30', '2019-05-02');

-- --------------------------------------------------------

--
-- Table structure for table `vehicle`
--

CREATE TABLE `vehicle` (
  `tempNo` int(10) NOT NULL,
  `name` varchar(20) NOT NULL,
  `aadhar` int(10) NOT NULL,
  `chassisNo` int(6) NOT NULL,
  `engineNo` varchar(10) NOT NULL,
  `vehicleClass` varchar(30) NOT NULL,
  `color` int(20) NOT NULL,
  `fuelType` varchar(20) NOT NULL,
  `seatingType` varchar(30) NOT NULL,
  `rto` varchar(30) NOT NULL,
  `status` int(1) NOT NULL,
  `vehicleNumber` int(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32;

--
-- Dumping data for table `vehicle`
--

INSERT INTO `vehicle` (`tempNo`, `name`, `aadhar`, `chassisNo`, `engineNo`, `vehicleClass`, `color`, `fuelType`, `seatingType`, `rto`, `status`, `vehicleNumber`) VALUES
(1234567890, 'Himanshu', 1234567890, 123455, '1234567890', 'C', 0, 'Petrol', 'Four Seater', 'Bahadurgarh', 1, 101);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `admin`
--
ALTER TABLE `admin`
  ADD PRIMARY KEY (`username`);

--
-- Indexes for table `dl`
--
ALTER TABLE `dl`
  ADD PRIMARY KEY (`aadhar`),
  ADD UNIQUE KEY `id` (`id`);

--
-- Indexes for table `ll`
--
ALTER TABLE `ll`
  ADD PRIMARY KEY (`aadhar`),
  ADD UNIQUE KEY `id` (`id`);

--
-- Indexes for table `vehicle`
--
ALTER TABLE `vehicle`
  ADD PRIMARY KEY (`tempNo`),
  ADD UNIQUE KEY `aadhar` (`aadhar`,`chassisNo`,`engineNo`,`vehicleNumber`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `dl`
--
ALTER TABLE `dl`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT for table `ll`
--
ALTER TABLE `ll`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
