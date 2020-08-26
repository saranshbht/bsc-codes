-- phpMyAdmin SQL Dump
-- version 4.9.0.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Nov 13, 2019 at 04:32 AM
-- Server version: 10.3.16-MariaDB
-- PHP Version: 7.3.7

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
  `password` varchar(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32;

--
-- Dumping data for table `admin`
--

INSERT INTO `admin` (`username`, `password`) VALUES
('admin', 'admin'),
('Hello', 'World');

-- --------------------------------------------------------

--
-- Table structure for table `dl`
--

CREATE TABLE `dl` (
  `dlno` bigint(10) DEFAULT NULL,
  `name` varchar(30) DEFAULT NULL,
  `fatherName` varchar(30) DEFAULT NULL,
  `dob` date DEFAULT NULL,
  `bloodGroup` varchar(3) DEFAULT NULL,
  `address` text DEFAULT NULL,
  `aadhar` bigint(10) NOT NULL,
  `gender` varchar(7) DEFAULT NULL,
  `mobileNumber` bigint(10) DEFAULT NULL,
  `email` varchar(30) DEFAULT NULL,
  `rto` varchar(30) DEFAULT NULL,
  `status` int(1) DEFAULT NULL,
  `id` bigint(10) NOT NULL,
  `validity` date DEFAULT NULL,
  `issueDate` date DEFAULT NULL,
  `examDate` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32;

--
-- Dumping data for table `dl`
--

INSERT INTO `dl` (`dlno`, `name`, `fatherName`, `dob`, `bloodGroup`, `address`, `aadhar`, `gender`, `mobileNumber`, `email`, `rto`, `status`, `id`, `validity`, `issueDate`, `examDate`) VALUES
(231143, 'Himanshu', 'Vikram Singh', '1999-12-24', 'B+', 'House', 1234567890, 'M', 2147483647, 'himanshu@gmail.com', 'Bahadurgarh', 1, 2, '2019-11-14', '2019-11-25', NULL);

-- --------------------------------------------------------

--
-- Table structure for table `ll`
--

CREATE TABLE `ll` (
  `llno` bigint(10) DEFAULT NULL,
  `name` varchar(30) DEFAULT NULL,
  `fatherName` varchar(30) DEFAULT NULL,
  `dob` date DEFAULT NULL,
  `bloodGroup` varchar(3) DEFAULT NULL,
  `address` text DEFAULT NULL,
  `aadhar` bigint(10) NOT NULL,
  `gender` varchar(7) DEFAULT NULL,
  `mobileNumber` bigint(10) DEFAULT NULL,
  `email` varchar(30) DEFAULT NULL,
  `rto` varchar(30) DEFAULT NULL,
  `status` int(1) DEFAULT NULL,
  `id` bigint(10) NOT NULL,
  `validity` date DEFAULT NULL,
  `issueDate` date DEFAULT NULL,
  `examDate` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32;

--
-- Dumping data for table `ll`
--

INSERT INTO `ll` (`llno`, `name`, `fatherName`, `dob`, `bloodGroup`, `address`, `aadhar`, `gender`, `mobileNumber`, `email`, `rto`, `status`, `id`, `validity`, `issueDate`, `examDate`) VALUES
(101, 'Himanshu', 'Vikram Singh', '1999-12-24', 'B+', 'House', 1234567891, 'M', 2147483647, 'himanshu@gmail.com', 'Bahadurgarh', 1, 1123, '2019-04-17', '2019-04-30', '2019-05-02'),
(NULL, 'Saransh Bhatia', 'Pritam Bhatia', '2019-11-13', 'B+', 'Moti Nagar', 1234567892, 'Male', 1234567890, 'fsjdlf@gmail.com', 'New Delhi', 0, 1124, NULL, NULL, NULL),
(NULL, 'fakljafk', 'kflakjf', '2019-11-14', 'faj', 'fjadfjl', 8473298472, 'df', 3284743928, 'jflj@gmail.com', 'fjdlfkaj', 0, 1125, NULL, NULL, '2019-11-27');

-- --------------------------------------------------------

--
-- Table structure for table `vehicle`
--

CREATE TABLE `vehicle` (
  `tempNo` bigint(10) NOT NULL,
  `name` varchar(20) DEFAULT NULL,
  `aadhar` bigint(10) DEFAULT NULL,
  `chassisNo` int(6) DEFAULT NULL,
  `engineNo` bigint(10) DEFAULT NULL,
  `vehicleClass` varchar(30) DEFAULT NULL,
  `color` varchar(20) DEFAULT NULL,
  `fuelType` varchar(20) DEFAULT NULL,
  `seatingType` varchar(30) DEFAULT NULL,
  `rto` varchar(30) DEFAULT NULL,
  `status` int(1) DEFAULT 0,
  `vehicleNumber` bigint(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32;

--
-- Dumping data for table `vehicle`
--

INSERT INTO `vehicle` (`tempNo`, `name`, `aadhar`, `chassisNo`, `engineNo`, `vehicleClass`, `color`, `fuelType`, `seatingType`, `rto`, `status`, `vehicleNumber`) VALUES
(1234567890, 'Himanshu', 1234567890, 123455, 1234567890, 'C', '0', 'Petrol', 'Four Seater', 'Bahadurgarh', 1, 101),
(4235542312, 'fafdsf', 4234341111, 343243, 4232342111, 'fasfds', 'fafsaf', 'fadfa', 'fdsfdsaf', 'fasdf', 0, NULL),
(6235542312, 'fafdsf', 4234341111, 343243, 4232342111, 'fasfds', 'fafsaf', 'fadfa', 'fdsfdsaf', 'fasdf', 0, NULL);

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
  MODIFY `id` bigint(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT for table `ll`
--
ALTER TABLE `ll`
  MODIFY `id` bigint(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=1126;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
