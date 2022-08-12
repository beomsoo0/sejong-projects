function varargout = m11_radio3(varargin)
% M11_RADIO3 MATLAB code for m11_radio3.fig
%      M11_RADIO3, by itself, creates a new M11_RADIO3 or raises the existing
%      singleton*.
%
%      H = M11_RADIO3 returns the handle to a new M11_RADIO3 or the handle to
%      the existing singleton*.
%
%      M11_RADIO3('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in M11_RADIO3.M with the given input arguments.
%
%      M11_RADIO3('Property','Value',...) creates a new M11_RADIO3 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before m11_radio3_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to m11_radio3_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help m11_radio3

% Last Modified by GUIDE v2.5 16-May-2015 09:30:03

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @m11_radio3_OpeningFcn, ...
                   'gui_OutputFcn',  @m11_radio3_OutputFcn, ...
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

% --- Executes just before m11_radio3 is made visible.
function m11_radio3_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to m11_radio3 (see VARARGIN)

% Choose default command line output for m11_radio3
handles.output = hObject;

set( handles.text2, 'String', ' ');
% Update handles structure
guidata(hObject, handles);

% UIWAIT makes m11_radio3 wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = m11_radio3_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;

% --- Executes when selected object is changed in uibuttongroup1.
function uibuttongroup1_SelectionChangedFcn(hObject, eventdata, handles) %#ok<*DEFNU>
% hObject    handle to the selected object in uibuttongroup1 
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
disp(hObject.String);
set( handles.text2, 'String', ...
    sprintf('You selected %s.', hObject.String ));
