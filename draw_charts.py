#!/usr/bin/env python3

import numpy as np
import matplotlib.pyplot as plt
import json

test_files = [
      "dickens"
    , "mozilla"
    , "mr"
    , "nci"
    , "ooffice"
    , "osdb"
    , "reymont"
    , "samba"
    , "sao"
    , "webster"
    , "xml"
    , "x-ray"
  ]

data=[]
with open("info.json") as test_info:
    data = json.load(test_info)

def draw_charts(get_info, step, title, ylabel):
    n_groups = len(test_files)
    data_lz4 = np.array([])
    data_zstd_min_compression = np.array([])
    data_zstd_max_compression = np.array([])

    for file in test_files:
        data_lz4 = np.append(data_lz4, get_info(data[file]["lz4-compress-max"]))
        data_zstd_min_compression = np.append(data_zstd_min_compression, get_info(data[file]["zstd-comp-1"]))
        data_zstd_max_compression = np.append(data_zstd_max_compression, get_info(data[file]["zstd-comp-7"]))

    fig, ax = plt.subplots()
    index = np.arange(n_groups)
    bar_width = 0.25
    opacity = 1

    rects1 = plt.bar(index, data_lz4, bar_width,
        alpha=opacity,
        color='b',
        label='lz4')

    rects2 = plt.bar(index + bar_width, data_zstd_min_compression, bar_width,
        alpha=opacity,
        color='g',
        label='zstd-min-compression')

    rects3 = plt.bar(index + bar_width * 2, data_zstd_max_compression, bar_width,
        alpha=opacity,
        color='r',
        label='zstd-max-compression')

    axes = plt.gca()
    y_min, y_max = axes.get_ylim()
    x_min, x_max = axes.get_xlim()
    plt.yticks(np.arange(y_min, y_max, step))


    plt.ylabel(ylabel)
    plt.title(title)
    plt.xticks(index + bar_width, test_files)
    plt.legend()

    plt.tight_layout()
    plt.grid(axis='y')
    plt.show()

def get_time(json_obj):
    return float(json_obj["comp-time"])

def get_сompression_coeff(json_obj):
    return float(json_obj["orig-size"]) / float(json_obj["comp-size"])

draw_charts(get_time, 0.25, 'Archivers speed', 'time (seconds)')
draw_charts(get_сompression_coeff, 0.5, 'Archivers compression', 'coeff')
