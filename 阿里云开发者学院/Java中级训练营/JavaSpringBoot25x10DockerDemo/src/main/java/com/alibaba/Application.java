package com.alibaba;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
/**
 * 《阿里巴巴Java Spring Boot 2.5.x开发实战课程》 完全免费 
 * 讲师 徐雷，阿里云大学讲师
第01课：Spring Boot2.0新特性和入门实战,https://yq.aliyun.com/live/583  
第02课：Spring Boot2.0开发MVC网站并显示图片,https://yq.aliyun.com/live/592
第03课：Spring Boot2.0实战MySQL和3个高级面试题，https://yq.aliyun.com/live/612
第04课：Spring Boot2.0实战MVC用户登录和注册和Java面试题https://yq.aliyun.com/live/644
第05课：Spring Boot2.0实战三层MVC架构实战与架构分层误区(Java面试题)https://yq.aliyun.com/live/655
第06课：Spring Boot2.0实战MyBatis与优化(Java面试题)https://yq.aliyun.com/live/687
第07课：Spring Boot2.0安全机制、漏洞与MVC身份验证实战(Java面试题) https://yq.aliyun.com/live/712
第08课：Spring Boot2.0自动化配置机制解析(Java面试题) 课件 PPT下载 https://yq.aliyun.com/live/729
第09课：Spring Boot2.0实战MongoDB4.0(MongoDB面试题) https://yq.aliyun.com/live/782
第10课：Spring Boot2.0实战高并发缓存Redis面试题) https://yq.aliyun.com/live/791
第11课：Spring Boot2.0实战RabbitMQ中间件与API原理解析 https://yq.aliyun.com/live/806
第12课：Spring Boot2.0性能监控实战与Actuator机制解析 https://yq.aliyun.com/live/815
第13课：Spring Boot2.0性能监控实战ElasticSearch搜索引擎中间件 https://yq.aliyun.com/live/844
第14课：Spring Boot 2.0实战MyBatis连接池阿里Druid与SQL性能监控 https://yq.aliyun.com/live/855
第15课：Spring Boot 2.0 API接口实战Swagger和Spring REST Docs https://yq.aliyun.com/live/859
第16课：Spring Boot 2.0实战Apache Kafka百万级高并发消息中间件 https://yq.aliyun.com/live/868
第17课：Spring Boot 2.0实战Docker容器与架构原理 https://yq.aliyun.com/live/880
第18课：Spring Boot2.0实战之制作Java Docker镜像与推送到DockerHub和阿里云仓库 https://yq.aliyun.com/live/906
第19课：Java Spring Cloud微服务架构模式与开发实战 https://yq.aliyun.com/live/916
第20课：Java Spring Boot 2.0 经典面试题与阿里巴巴内部招聘岗位   https://yq.aliyun.com/live/935
 */
@SpringBootApplication
@RestController
public class Application {

    @RequestMapping("/hi")
    public String hello() {
        return "Hi Docker Java Spring Boot 2.5.2";
    }

    public static void main(String[] args) {
        SpringApplication.run(Application.class, args);
    }

}
