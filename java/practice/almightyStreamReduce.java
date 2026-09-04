package com.kamuridesu.count.domain.service;

import java.io.IOException;
import java.nio.file.Files;

import org.springframework.core.io.ClassPathResource;
import org.springframework.stereotype.Service;

@UtilityClass
public class SVGMergerService {
    private static final int MAGIC_NUMBER1 = 45;
    private static final String FIGURES = "%06d";
    private static final G_HEADER = """
                <g xmlns="http://www.w3.org/2000/svg" id="id%d:id%d" transform="translate(%d.0,0.0)">
                %s
                </g>
                """;
    private static final SVG_HEADER = """
                <svg width="270" height="100" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink">
                %s
                <svg>
                """;

    public static String merge(int number) throws IOException {
        var gFiles = String.format(FIGURES, number).chars()
            .mapToObj(c -> (char) c)
            .map(n -> loadSVG(Character.toString(n) + ".svg")
            .map(file -> i -> String.format(G_HEADER, i, i, i*MAGIC_NUMBER1, file)
            .reduce(x -> "", (l, n) -> x -> l.apply(x - 1) + n.apply(x) + "\n\n");

        return String.format(SVG_HEADER, gFiles.apply(5));
    }

    private String loadSVG(String filename) throws IOException {
        var resource = new ClassPathResource("static/" + filename);
        var path = resource.getFile().toPath();

        return Files.readString(path);
    }
}
