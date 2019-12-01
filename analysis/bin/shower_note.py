# Select files in folder
# Code from: https://codereview.stackexchange.com/questions/162920/file-selection-button-for-jupyter-notebook

import pandas as pd
import numpy as np
import matplotlib as mp
import matplotlib.pyplot as plt
import matplotlib as mpl
import plotly.offline as py
import plotly.tools as tls
import plotly.graph_objs as go
import plotly.io as pio
import datetime as dt
import time
pio.templates.default = "none" # IMPORTANT, otherwise plotly would use it's own (ugly) style set
import ipywidgets as widgets
from ipywidgets import interact, interact_manual, interactive, fixed

# Control figure size
mpl.rcParams['figure.figsize']=(7,5)
py.init_notebook_mode(connected=False)
# Use plotly as gifure output
def plotly_show():
    fig = plt.gcf()
    py.iplot_mpl(fig, strip_style= False, verbose=False)

import traitlets
from ipywidgets import widgets
from IPython.display import display
from tkinter import Tk, filedialog

class SelectFilesButton(widgets.Button):
    """A file widget that leverages tkinter.filedialog."""

    def __init__(self):
        super(SelectFilesButton, self).__init__()
        # Add the selected_files trait
        self.add_traits(files=traitlets.traitlets.List())
        # Create the button.
        self.description = "Select Files"
        self.icon = "square-o"
        self.style.button_color = "orange"
        # Set on click behavior.
        self.on_click(self.select_files)

    @staticmethod
    def select_files(b):
        """Generate instance of tkinter.filedialog.

        Parameters
        ----------
        b : obj:
            An instance of ipywidgets.widgets.Button 
        """
        with out:
            try:
                # Create Tk root
                root = Tk()
                # Hide the main window
                root.withdraw()
                # Raise the root to the top of all windows.
                root.call('wm', 'attributes', '.', '-topmost', True)
                # List of selected fileswill be set to b.value
                b.files = filedialog.askopenfilename(multiple=True)

                b.description = "Files Selected"
                b.icon = "check-square-o"
                b.style.button_color = "lightgreen"
            except:
                pass
out = widgets.Output()

# Color definition from coolors.co
colors = {'Fall_rgb': ['rgb(85,5,39)', 'rgb(104,142,38)'],
          'Fall_rgba': ['rgba(85,5,39,0.3)', 'rgba(104,142,38,0.3)']
         }
colors_df = pd.DataFrame(colors)

# Plot Time difference distribution as a scatter plot
# Options to pass to functions:
#   - dataframe (fixed): dataframe containing the chosen data
#   - name (drop_down): filename in dataframe
#   - conv_data (check_box): convert the times into datetime format (time consuming, only check for final plot)
#   - t_cut (drop_down): time cut in [us] for highlighting coincident events
#   - yrange (drop_down): pre-selectable y-axis scaling in [us]
def scatplot(dataframe,
             name,
             conv_date = False,
             t_cut = 10,
             yrange = 100
            ):

    # Some style features
    hist_linewidth = 3
    #coincidence cut
    data = dataframe[name]
    t_cut = t_cut*1e3 # in ns
    data_cut = data[(data.tdiff <= t_cut) & (data.tdiff >= -t_cut)]
    # Prepare data for highlighting the time cut
    cut_upper = np.full(len(data.ts),t_cut*1e0)
    cut_lower = np.full(len(data.ts),-t_cut*1e0)
    cut_lower = cut_lower[::-1]
    x_rev = data.ts[::-1]
    x_prepared = np.append(data.ts, x_rev)
    # Convert the timestamps to datetime format for plotting
    if conv_date:
        xdata1 = [(dt.datetime.fromtimestamp(data.ts[index])) for index, rows in data.ts.iteritems()] 
        xdata2 = [(dt.datetime.fromtimestamp(data_cut.ts[index])) for index, rows in data_cut.ts.iteritems()]
        xdata3 = [(dt.datetime.fromtimestamp(x_prepared[i])) for i in np.arange(0,len(x_prepared),1)]
        xaxis_type = "date"
    else: 
        xdata1 = data.ts
        xdata2 = data_cut.ts
        xdata3 = x_prepared
        xaxis_type = "-"

    fig = go.FigureWidget()
    trace1 = go.Scattergl( # scattergl for increased speed!
            x = xdata1, 
            y = data.tdiff,
            mode = 'markers',
            marker_color = colors_df['Fall_rgb'][1], 
            marker_size = 5,
            name = "Uncut"
        )
        # Cut data
    trace2 = go.Scattergl( # scattergl for increased speed!
            x = xdata2,
            y = data_cut.tdiff,
            mode = 'markers',
    #         marker_color = 'rgb(0,176,246)',
            marker_color = colors_df['Fall_rgb'][0],
            marker_size = 10,
            name = "Cut",
    )
    trace3 = go.Scatter(
            x = xdata3,
            y = np.append(cut_upper,cut_lower),
            fill='toself',
            fillcolor=colors_df['Fall_rgba'][0],
            line_color='rgba(255,255,255,0)',
            showlegend=False,
            name='Fair',
    )


    hist11 = go.Histogram(x=xdata1, name='x density', 
                          marker=dict(
                              color=colors_df['Fall_rgb'][1], 
                              opacity=0.7, 
                              line=dict(
                                color=colors_df['Fall_rgb'][1],
                                width=hist_linewidth
                              )
                          ),
                          yaxis='y2'
                         )
    hist12 = go.Histogram(y=data.tdiff, name='y density', 
                          marker=dict(
                              color=colors_df['Fall_rgb'][1], 
                              opacity=0.7, 
                              line=dict(
                                color=colors_df['Fall_rgb'][1],
                                width=hist_linewidth
                              )
                          ),
                          xaxis='x2'
                         )
    hist21 = go.Histogram(x=xdata2, name='x density', 
                          marker=dict(
                              color=colors_df['Fall_rgb'][0], 
                              opacity=0.7, 
                              line=dict(
                                color=colors_df['Fall_rgb'][0],
                                width=hist_linewidth
                              )
                          ),
                          yaxis='y2'
                         )
    hist22 = go.Histogram(y=data.tdiff, name='y density', 
                          marker=dict(
                              color=colors_df['Fall_rgb'][0], 
                              opacity=0.7, 
                              line=dict(
                                color=colors_df['Fall_rgb'][0],
                                width=hist_linewidth
                              )
                          ),
                          xaxis='x2'
                         )

    # Data to plot
    plot_data = [trace1, trace2, trace3, hist11, hist12, hist21, hist22]

    layout = dict(title = 'Time Distribution Plot',
                  yaxis = dict(mirror=True, ticks='inside', showline=True, 
                               showexponent = 'all', exponentformat = 'e', range=[-100000, 100000], 
                               title="Time Difference [ns]",
                               domain=[0, 0.85], showgrid=True, gridwidth=2, zeroline=True),
                  xaxis = dict(zeroline = False, mirror=True, ticks='inside', showline=True,
                               title = "Unix Timestamp", type = xaxis_type,
                               domain=[0, 0.85], showgrid=True, gridwidth=2),
                  xaxis_rangeslider_visible=False,
                  xaxis_tickformat = '%d %B <br>%Y<br>%H:%M:%S',
                  showlegend=True,
                  margin=dict(t=50),
                  hovermode='closest',
                  bargap=0,
                  xaxis2=dict(
                      domain=[0.85, 1], showgrid=True, gridwidth=2, zeroline=False,
                      mirror=True,
                      ticks='inside',
                      showline=True,
                    title='Y-Projection',
                  ),
                  yaxis2=dict(
                      domain=[0.85, 1], showgrid=True, gridwidth=2, zeroline=False,
                      mirror=True,
                      ticks='inside',
                      showline=True,
                      title='X-Projection',
                  ),
                  height=600,
                 )

    def do_zoom(layout, xaxis_range, yaxis_range):
        # Reconvert xaxis to timestamp format for comparison with data
        if conv_date:
            # Check the date format given by xaxis_range
            if (len(xaxis_range[0]) < 16):
                xaxis_range0 = xaxis_range[0] + " 00:00"
            else:
                xaxis_range0 = xaxis_range[0]
            if (len(xaxis_range[1]) < 16):
                xaxis_range1 = xaxis_range[1] + " 00:00"
            else:
                xaxis_range1 = xaxis_range[1]
            # Convert to timestamp
            xaxis_range0_ts = time.mktime(dt.datetime.strptime(xaxis_range0[:16], "%Y-%m-%d %H:%M").timetuple())
            xaxis_range1_ts = time.mktime(dt.datetime.strptime(xaxis_range1[:16], "%Y-%m-%d %H:%M").timetuple())
            xdata1 = np.asarray(fig.data[0].x)
            xdata2 = np.asarray(fig.data[1].x)
        else:
            xaxis_range0_ts = xaxis_range[0]
            xaxis_range1_ts = xaxis_range[1]
            xdata1 = data.ts
            xdata2 = data_cut.ts
        # Get all the relevant indices for the data-points which are included in the current zoom
        inds1 = ((xaxis_range0_ts <= data.ts) & (data.ts <= xaxis_range1_ts) &
                (yaxis_range[0] <= data.tdiff) & (data.tdiff <= yaxis_range[1]))
        inds2 = ((xaxis_range0_ts <= data_cut.ts) & (data_cut.ts <= xaxis_range1_ts) &
                (yaxis_range[0] <= data_cut.tdiff) & (data_cut.tdiff <= yaxis_range[1]))
        # Update the Histograms
        with fig.batch_update():
            fig.data[3].x = xdata1[inds1] # are the histograms
            fig.data[4].y = data.tdiff[inds1] # are the histograms
            fig.data[5].x = xdata2[inds2] # are the histograms
            fig.data[6].y = data_cut.tdiff[inds2] # are the histograms


    fig = go.FigureWidget(data=plot_data, layout=layout)
    fig.update_layout(barmode='overlay')

    fig.layout.on_change(do_zoom, 'xaxis.range', 'yaxis.range')

    return(fig)