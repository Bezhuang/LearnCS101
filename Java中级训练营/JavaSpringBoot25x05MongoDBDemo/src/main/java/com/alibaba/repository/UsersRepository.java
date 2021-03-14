package com.alibaba.repository;

import java.util.List;

import org.springframework.data.mongodb.repository.MongoRepository;

import com.alibaba.models.Users;

public interface UsersRepository extends MongoRepository<Users, Integer> {
	public List<Users> getUserByName(String name);
	public Users getUserByNameAndPassword(String name, String password);
	public Users getUserById(int id);
}
