import numpy as np
import matplotlib.pyplot as plt
import matplotlib as mpl
from matplotlib.font_manager import FontProperties
from scipy.interpolate import PchipInterpolator

# default settings for matplotlib
plt.style.use('default')
plt.rcParams['axes.unicode_minus'] = False
plt.rcParams['figure.figsize'] = (9, 6)
rc = {
    "font.family": "times new roman",
    "mathtext.fontset": "stix",
    "axes.linewidth": 1.1,
    "xtick.direction": "in",
    "ytick.direction": "in",
    "axes.edgecolor": "black",
    "xtick.color": "black",
    "ytick.color": "black",
}
mpl.rcParams.update(rc)
zh_font = FontProperties(fname='C:/Windows/Fonts/simhei.ttf')  # 设置中文字体
# plt.rcParams['figure.dpi'] = 100  # 设置图像分辨率

# 01 D (V, mA)
D_U = np.array([0, 0.108, 0.211, 0.315, 0.417, 0.515, 0.605, 0.629, 0.647, 0.663, 0.693, 0.720, 0.733, 0.740, 0.747, 0.753, 0.756, 0.760, 0.765, 0.771, 0.774])
D_I = np.array([0, 0.00, 0.00, 0.00, 0.00, 0.08, 0.74, 1.17, 1.84, 2.65, 5.54, 10.93, 15.17, 18.45, 22.53, 25.91, 29.20, 31.88, 37.35, 41.34, 45.05])
# 02 Red LED (V, mA)
RedLED_U = np.array([0, 1.746, 1.808, 1.871, 1.912, 1.945, 1.975, 1.998, 2.023, 2.046, 2.072, 2.085, 2.105, 2.122, 2.139, 2.161,2.170, 2.185, 2.203, 2.211, 2.229])
RedLED_I = np.array([0, 0.43, 1.06, 2.16, 3.12, 4.11, 5.15, 6.05, 7.02, 8.12, 9.33, 10.02, 11.17, 12.24, 13.08, 14.28, 15.20, 16.14, 17.28, 17.98, 19.06])
# 03 Green LED (V, mA)
GreenLED_U = np.array([0, 2.313, 2.373, 2.440, 2.546, 2.605, 2.685, 2.726, 2.781, 2.830, 2.877, 2.897, 2.918, 2.931, 2.959, 2.972, 2.995, 3.012, 3.036, 3.053, 3.068])
GreenLED_I = np.array([0, 0.02, 1.15, 1.83, 3.11, 3.99, 5.19, 6.01, 7.07, 8.19, 9.31, 9.96, 11.05, 12.09, 13.06, 14.21, 15.34, 16.23, 16.99, 18.17, 19.40])
# 04 Blue LED (V, mA)
BlueLED_U = np.array([0, 2.609, 2.658, 2.725, 2.784, 2.821, 2.866, 2.896, 2.929, 2.972, 3.011, 3.036, 3.076, 3.114, 3.132, 3.153, 3.183, 3.218, 3.231, 3.258, 3.288])
BlueLED_I = np.array([0, 0.23, 0.99, 2.12, 3.38, 4.40, 5.53, 6.51, 7.58, 8.69, 9.19, 10.31, 11.19, 12.34, 13.32, 14.12, 15.70, 16.74, 17.74, 18.66, 19.22])
# 05 DW (V, mA)
DW_U = np.array([0, -1.920, -2.415, -2.623, -2.819, -2.934, -2.983, -3.031, -3.084, -3.145, -3.193, -3.250, -3.282, -3.314, -3.365, -3.379, -3.406, -3.434, -3.462, -3.478, -3.498])
DW_I = np.array([0, 0.24, 1.19, 2.01, 3.44, 4.62, 5.25, 5.94, 6.77, 8.01, 8.86, 10.26, 11.41, 12.55, 13.78, 14.22, 15.34, 16.43, 17.74, 18.55, 19.32])

def build_spline(u, i, num=350):
    idx = np.argsort(u)
    u_sorted = u[idx]
    i_sorted = i[idx]
    u_smooth = np.linspace(u_sorted.min(), u_sorted.max(), num)
    # PCHIP 对单调数据更稳健，能减少普通三次样条的过冲
    spline_local = PchipInterpolator(u_sorted, i_sorted)
    i_smooth = spline_local(u_smooth)
    return u_sorted, i_sorted, u_smooth, i_smooth, spline_local


def tangent_x_intercept(u_smooth, i_smooth, spline_local, mode='max'):
    slopes = spline_local.derivative()(u_smooth)
    if mode == 'min':
        idx = np.argmin(slopes)
    else:
        idx = np.argmax(slopes)
    u_star = u_smooth[idx]
    i_star = i_smooth[idx]
    slope = slopes[idx]
    u_intercept = u_star - i_star / slope
    return u_star, i_star, slope, u_intercept


def style_axis(ax):
    ax.minorticks_on()
    ax.grid(True, which='major', linestyle='--', linewidth=0.7, color='0.7')
    ax.grid(True, which='minor', linestyle=':', linewidth=0.5, color='0.85')
    # 显式画出 x 轴参考线，保证打印或缩放时仍清晰可见
    ax.axhline(0, color='black', linewidth=1.0, zorder=7)


# 拟合数据
D_u_sorted, D_i_sorted, D_U_smooth, D_I_smooth, spline_d = build_spline(D_U, D_I)

# LED 图不显示左侧起始段（去掉 0V 的首个点）
R_u_sorted, R_i_sorted, REDLED_U_smooth, RedLED_I_smooth, spline_r = build_spline(RedLED_U[1:], RedLED_I[1:])
G_u_sorted, G_i_sorted, GREENLED_U_smooth, GreenLED_I_smooth, spline_g = build_spline(GreenLED_U[1:], GreenLED_I[1:])
B_u_sorted, B_i_sorted, BLUELED_U_smooth, BlueLED_I_smooth, spline_b = build_spline(BlueLED_U[1:], BlueLED_I[1:])
DW_u_sorted, DW_i_sorted, DW_U_smooth, DW_I_smooth, spline_dw = build_spline(DW_U, DW_I)

# D: 最大斜率切线法求导通电压
D_u_star, D_i_star, D_slope, D_u_on = tangent_x_intercept(D_U_smooth, D_I_smooth, spline_d, mode='max')
D_u_tangent = np.linspace(max(D_U.min(), D_u_on - 0.02), D_U.max() + 0.02, 340)
D_i_tangent = D_slope * (D_u_tangent - D_u_star) + D_i_star

# LED: 同样使用最大斜率切线法
R_u_star, R_i_star, R_slope, R_u_on = tangent_x_intercept(REDLED_U_smooth, RedLED_I_smooth, spline_r, mode='max')
G_u_star, G_i_star, G_slope, G_u_on = tangent_x_intercept(GREENLED_U_smooth, GreenLED_I_smooth, spline_g, mode='max')
B_u_star, B_i_star, B_slope, B_u_on = tangent_x_intercept(BLUELED_U_smooth, BlueLED_I_smooth, spline_b, mode='max')
R_u_tangent = np.linspace(max(REDLED_U_smooth.min(), R_u_on - 0.03), REDLED_U_smooth.max() + 0.03, 320)
R_i_tangent = R_slope * (R_u_tangent - R_u_star) + R_i_star
G_u_tangent = np.linspace(max(GREENLED_U_smooth.min(), G_u_on - 0.03), GREENLED_U_smooth.max() + 0.03, 320)
G_i_tangent = G_slope * (G_u_tangent - G_u_star) + G_i_star
B_u_tangent = np.linspace(max(BLUELED_U_smooth.min(), B_u_on - 0.03), BLUELED_U_smooth.max() + 0.03, 320)
B_i_tangent = B_slope * (B_u_tangent - B_u_star) + B_i_star

# DW: 取最小斜率（负斜率绝对值最大）切线与 x 轴交点，作为稳压特征电压
DW_u_star, DW_i_star, DW_slope, DW_u_z = tangent_x_intercept(DW_U_smooth, DW_I_smooth, spline_dw, mode='min')
DW_u_tangent = np.linspace(DW_U.min() - 0.05, min(0.0, DW_u_z + 0.05), 340)
DW_i_tangent = DW_slope * (DW_u_tangent - DW_u_star) + DW_i_star

fig, axes = plt.subplots(2, 2, figsize=(13, 9), layout='constrained', facecolor='white')

# axes[0][0]: 晶体二极管 D
ax = axes[0][0]
ax.plot(D_U_smooth, D_I_smooth, color='black', linewidth=1.8, label='曲线拟合', zorder=10)
ax.scatter(D_u_sorted, D_i_sorted, facecolors='white', edgecolors='black', s=22, linewidths=0.9, label='实验数据点', zorder=11)
ax.plot(D_u_tangent, D_i_tangent, color='black', linestyle='--', linewidth=1.2, zorder=9)
ax.scatter([D_u_on], [0], color='black', s=40, marker='x', linewidths=1.2, label=r'导通电压 $U_{on}$', zorder=12)
ax.annotate(
    rf'$U_{{on}}={D_u_on:.4f}\,\mathrm{{V}}$',
    xy=(D_u_on, 0),
    xytext=(D_u_on - 0.5, 13),
    fontsize=13,
    arrowprops=dict(arrowstyle='->', lw=1.0, color='black'),
)
ax.set_title('晶体二极管 D', fontproperties=zh_font)
ax.set_xlabel(r'电压$\mathrm{U}\,(\mathrm{V})$', fontproperties=zh_font)
ax.set_ylabel(r'电流$\mathrm{I}\,(\mathrm{mA})$', fontproperties=zh_font)
ax.set_xlim(D_U.min(), D_U.max() + 0.03)
ax.set_ylim(-1.2, 52)
ax.set_xticks(np.arange(0, 0.81, 0.1))
ax.set_yticks(np.arange(0, 51, 10))
style_axis(ax)
ax.legend(prop=zh_font, frameon=True, facecolor='white', edgecolor='black', fontsize=9)

# axes[0][1]: 三种 LED 合并
ax = axes[0][1]
ax.plot(REDLED_U_smooth, RedLED_I_smooth, color='black', linewidth=1.6, linestyle='-', label='红色LED曲线拟合', zorder=10)
ax.scatter(R_u_sorted, R_i_sorted, facecolors='white', edgecolors='black', s=18, marker='o', linewidths=0.8, zorder=11)
ax.plot(GREENLED_U_smooth, GreenLED_I_smooth, color='black', linewidth=1.4, linestyle='--', label='绿色LED曲线拟合', zorder=10)
ax.scatter(G_u_sorted, G_i_sorted, facecolors='white', edgecolors='black', s=18, marker='s', linewidths=0.8, zorder=11)
ax.plot(BLUELED_U_smooth, BlueLED_I_smooth, color='black', linewidth=1.4, linestyle='-.', label='蓝色LED曲线拟合', zorder=10)
ax.scatter(B_u_sorted, B_i_sorted, facecolors='white', edgecolors='black', s=18, marker='^', linewidths=0.8, zorder=11)
ax.plot(R_u_tangent, R_i_tangent, color='black', linestyle=':', linewidth=1.0, zorder=9)
ax.plot(G_u_tangent, G_i_tangent, color='black', linestyle=':', linewidth=1.0, zorder=9)
ax.plot(B_u_tangent, B_i_tangent, color='black', linestyle=':', linewidth=1.0, zorder=9)
ax.scatter([R_u_on, G_u_on, B_u_on], [0, 0, 0], color='black', s=32, marker='x', linewidths=1.1, zorder=12)
ax.vlines([R_u_on, G_u_on, B_u_on], ymin=0, ymax=1.2, colors='black', linestyles=':', linewidth=0.9, zorder=8)
ax.annotate(
    rf'$U_{{on,R}}={R_u_on:.3f}\,\mathrm{{V}}$',
    xy=(R_u_on, 0),
    xytext=(R_u_on - 0.5, 4.4),
    fontsize=13,
    arrowprops=dict(arrowstyle='->', lw=0.9, color='black'),
)
ax.annotate(
    rf'$U_{{on,G}}={G_u_on:.3f}\,\mathrm{{V}}$',
    xy=(G_u_on, 0),
    xytext=(G_u_on - 0.6, 6.4),
    fontsize=13,
    arrowprops=dict(arrowstyle='->', lw=0.9, color='black'),
)
ax.annotate(
    rf'$U_{{on,B}}={B_u_on:.3f}\,\mathrm{{V}}$',
    xy=(B_u_on, 0),
    xytext=(B_u_on - 0.05, 4.0),
    fontsize=13,
    arrowprops=dict(arrowstyle='->', lw=0.9, color='black'),
)
ax.set_title('发光二极管 LED', fontproperties=zh_font)
ax.set_xlabel(r'电压$\mathrm{U}\,(\mathrm{V})$', fontproperties=zh_font)
ax.set_ylabel(r'电流$\mathrm{I}\,(\mathrm{mA})$', fontproperties=zh_font)
ax.set_xlim(1.5, 3.4)
ax.set_ylim(-1.0, 21.0)
ax.set_xticks(np.arange(1.5, 3.4, 0.3))
ax.set_yticks(np.arange(0, 21, 5))
style_axis(ax)
ax.legend(prop=zh_font, frameon=True, facecolor='white', edgecolor='black', fontsize=8.5)

# axes[1][0]: 稳压二极管 DW（仿照 D）
ax = axes[1][0]
ax.plot(DW_U_smooth, DW_I_smooth, color='black', linewidth=1.8, label='曲线拟合', zorder=10)
ax.scatter(DW_u_sorted, DW_i_sorted, facecolors='white', edgecolors='black', s=22, linewidths=0.9, label='实验数据点', zorder=11)
ax.plot(DW_u_tangent, DW_i_tangent, color='black', linestyle='--', linewidth=1.2, zorder=9)
ax.scatter([DW_u_z], [0], color='black', s=40, marker='x', linewidths=1.2, label=r'特征电压 $U_{z}$', zorder=12)
ax.annotate(
    rf'$U_{{z}}={DW_u_z:.4f}\,\mathrm{{V}}$',
    xy=(DW_u_z, 0),
    xytext=(DW_u_z + 0.55, 8),
    fontsize=13,
    arrowprops=dict(arrowstyle='->', lw=1.0, color='black'),
)
ax.set_title('稳压二极管 DW', fontproperties=zh_font)
ax.set_xlabel(r'电压$\mathrm{U}\,(\mathrm{V})$', fontproperties=zh_font)
ax.set_ylabel(r'电流$\mathrm{I}\,(\mathrm{mA})$', fontproperties=zh_font)
ax.set_xlim(DW_U.min() - 0.05, 0.1)
ax.set_ylim(-1.0, 20.5)
ax.set_xticks(np.arange(-3.5, 0.1, 0.5))
ax.set_yticks(np.arange(0, 21, 5))
style_axis(ax)
ax.legend(prop=zh_font, frameon=True, facecolor='white', edgecolor='black', fontsize=9)

# axes[1][1]: 空白
axes[1][1].axis('off')

plt.show()
fig.savefig('figure.png', dpi=600, bbox_inches='tight')