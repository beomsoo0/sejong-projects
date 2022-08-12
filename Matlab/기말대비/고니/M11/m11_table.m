function varargout = m11_table(varargin)
% M11_TABLE MATLAB code for m11_table.fig
%      M11_TABLE, by itself, creates a new M11_TABLE or raises the existing
%      singleton*.
%
%      H = M11_TABLE returns the handle to a new M11_TABLE or the handle to
%      the existing singleton*.
%
%      M11_TABLE('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in M11_TABLE.M with the given input arguments.
%
%      M11_TABLE('Property','Value',...) creates a new M11_TABLE or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before m11_table_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to m11_table_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help m11_table

% Last Modified by GUIDE v2.5 16-May-2015 14:15:26

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @m11_table_OpeningFcn, ...
                   'gui_OutputFcn',  @m11_table_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before m11_table is made visible.
function m11_table_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to m11_table (see VARARGIN)

% Choose default command line output for m11_table
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes m11_table wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = m11_table_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;
