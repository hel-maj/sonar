/* ===== 23c61ba20 license.activation_dialog:333 ===== */
/* ghidra_name=FUN_23c61ba20 entry=23c61ba20 size=2996 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23c61ba20(longlong param_1,undefined8 param_2,undefined8 *param_3,longlong *param_4)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  undefined8 uVar7;
  code *pcVar8;
  longlong lVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  undefined4 uVar15;
  longlong *plVar16;
  longlong *plStack_90;
  longlong *plStack_78;
  undefined8 uStack_70;
  longlong *plStack_68;
  
  plVar10 = _DAT_23ee29ea8;
  plVar1 = (longlong *)param_3[1];
  plVar2 = (longlong *)*param_3;
  plVar3 = (longlong *)param_3[2];
  if (_DAT_23ee29ea8 == (longlong *)0x0) {
LAB_23c61ba72:
    param_4 = (longlong *)0x30;
    _DAT_23ee29ea8 = (longlong *)FUN_23e91f3b0(param_1,DAT_23ee29ea0,DAT_23ee29f70);
  }
  else {
    lVar9 = *_DAT_23ee29ea8;
    if (1 < lVar9) {
      *_DAT_23ee29ea8 = lVar9 + -1;
      goto LAB_23c61ba72;
    }
    if (_DAT_23ee29ea8[2] != 0) {
      *_DAT_23ee29ea8 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23c61ba72;
    }
  }
  plVar6 = _DAT_23ee29ea8;
  lVar9 = *(longlong *)(param_1 + 0x38);
  plVar10 = _DAT_23ee29ea8 + 9;
  lVar4 = *(longlong *)(lVar9 + 8);
  _DAT_23ee29ea8[0xf] = lVar4;
  *(longlong **)(lVar9 + 8) = plVar10;
  if ((lVar4 != 0) &&
     (((*(char *)(lVar4 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar4 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar4 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar4 + 0x38))
       ) && (plVar6[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar4 + 0x28);
    *(longlong **)(plVar6[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar6 = *plVar6 + 1;
  uVar7 = _DAT_23ee294d0;
  *(undefined4 *)(plVar6 + 8) = 0;
  lVar9 = FUN_23ead6c20();
  if (lVar9 == 0) {
    plVar10 = (longlong *)0x0;
    plVar16 = (longlong *)0x0;
    FUN_23e915740(param_1,&plStack_78,DAT_23ee29038);
    uVar15 = 0x150;
    plVar12 = (longlong *)0x0;
    plVar11 = plStack_68;
    plVar13 = DAT_23ed6a4f8;
    plStack_90 = plStack_78;
    uVar7 = uStack_70;
    goto joined_r0x00023c61c0df;
  }
  plVar10 = (longlong *)_PyDict_NewPresized(3);
  PyDict_SetItem(plVar10,uVar7,lVar9);
  PyDict_SetItem(plVar10,DAT_23ee29478,_DAT_23ee294d8);
  PyDict_SetItem(plVar10,DAT_23ee294a8,_DAT_23ee294e0);
  plVar11 = (longlong *)FUN_23ead7550();
  if (plVar11 == (longlong *)0x0) {
    FUN_23e915740(param_1,&plStack_78,DAT_23ee29000);
    uVar7 = uStack_70;
    plStack_90 = plStack_78;
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    plVar10 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    uVar15 = 0x153;
    plVar16 = (longlong *)0x0;
    plVar11 = plStack_68;
    plVar13 = DAT_23ed6a4f8;
    goto joined_r0x00023c61c0df;
  }
  plVar12 = (longlong *)FUN_23e973620(plVar10,plVar3);
  if (plVar12 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    if (plStack_90 != (longlong *)0x0) {
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
        plStack_90 = *(longlong **)(param_1 + 0x60);
      }
      plVar11 = *(longlong **)(param_1 + 0x70);
      plVar10 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar16 = (longlong *)0x0;
      uVar15 = 0x153;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar13 = DAT_23ed6a4f8;
      uVar7 = *(undefined8 *)(param_1 + 0x68);
      goto joined_r0x00023c61c0df;
    }
    *plVar11 = *plVar11 + 1;
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
  }
  else {
    *plVar10 = *plVar10 + -1;
    plVar11 = plVar12;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
  }
  plVar12 = _DAT_23ee294e8;
  lVar9 = *(longlong *)(param_1 + 0x10);
  plVar10 = *(longlong **)(lVar9 + 0xe38);
  if (plVar10 == (longlong *)0x0) {
    plVar10 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,5);
  }
  else {
    lVar4 = plVar10[3];
    *(int *)(lVar9 + 0xec8) = *(int *)(lVar9 + 0xec8) + -1;
    *(longlong *)(lVar9 + 0xe38) = lVar4;
    *plVar10 = 1;
  }
  pcVar8 = _PyRuntime_exref;
  *(undefined1 (*) [16])(plVar10 + 4) = (undefined1  [16])0x0;
  lVar9 = *(longlong *)(pcVar8 + 0x1f8);
  *(undefined1 (*) [16])(plVar10 + 6) = (undefined1  [16])0x0;
  lVar9 = *(longlong *)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
  lVar4 = plVar10[-1];
  puVar5 = *(undefined8 **)(lVar9 + 8);
  *puVar5 = plVar10 + -2;
  plVar10[-2] = lVar9;
  plVar10[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar5;
  *(longlong **)(lVar9 + 8) = plVar10 + -2;
  plVar13 = DAT_23ed6a4c0;
  *plVar12 = *plVar12 + 1;
  plVar10[3] = (longlong)plVar12;
  uVar7 = DAT_23ed6cd28;
  plVar16 = &DAT_23ed6cce0;
  plVar12 = plVar11;
  if (plVar13 == (longlong *)0x0) {
    plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
    if (plVar13 != (longlong *)0x0) {
      *plVar13 = *plVar13 + 1;
      DAT_23ed6a4c0 = plVar13;
      goto LAB_23c61bc48;
    }
LAB_23c61c5d0:
    PyErr_PrintEx(0);
    Py_Exit(1);
LAB_23c61c5e8:
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar11 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar15 = 0x15a;
    uVar7 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *param_4 = *param_4 + -1;
    plVar13 = DAT_23ed6a4f8;
    if (*param_4 == 0) {
      (**(code **)(param_4[1] + 0x30))(param_4);
      uVar15 = 0x15a;
      plVar13 = DAT_23ed6a4f8;
    }
  }
  else {
LAB_23c61bc48:
    uStack_70 = uVar7;
    plStack_78 = plVar11;
    lVar9 = FUN_23e94ed00(param_1,plVar13,&plStack_78);
    if (lVar9 != 0) {
      plVar10[4] = lVar9;
      plVar13 = _DAT_23ee294f0;
      *_DAT_23ee294f0 = *_DAT_23ee294f0 + 1;
      plVar10[5] = (longlong)plVar13;
      uVar7 = DAT_23ed6cd28;
      if (DAT_23ed6a4c0 == (longlong *)0x0) {
        plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
        if (plVar13 == (longlong *)0x0) goto LAB_23c61c5d0;
        *plVar13 = *plVar13 + 1;
        DAT_23ed6a4c0 = plVar13;
      }
      uStack_70 = uVar7;
      plStack_78 = plVar1;
      lVar9 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_78);
      if (lVar9 != 0) {
        plVar10[6] = lVar9;
        plVar16 = _DAT_23ee294f8;
        *_DAT_23ee294f8 = *_DAT_23ee294f8 + 1;
        plVar10[7] = (longlong)plVar16;
        plVar16 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar10);
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if (plVar16 == (longlong *)0x0) {
          plStack_90 = *(longlong **)(param_1 + 0x60);
          plVar11 = *(longlong **)(param_1 + 0x70);
          plVar10 = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar15 = 0x155;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar13 = DAT_23ed6a4f8;
          uVar7 = *(undefined8 *)(param_1 + 0x68);
          goto joined_r0x00023c61c0df;
        }
        plVar10 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23ee29220);
        if (plVar10 != (longlong *)0x0) {
          plVar13 = (longlong *)FUN_23e8bc2f0(plVar10,_DAT_23ee29500);
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          if (plVar13 == (longlong *)0x0) {
            plStack_90 = *(longlong **)(param_1 + 0x60);
            plVar11 = *(longlong **)(param_1 + 0x70);
            plVar10 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar15 = 0x156;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar13 = DAT_23ed6a4f8;
            uVar7 = *(undefined8 *)(param_1 + 0x68);
            goto joined_r0x00023c61c0df;
          }
          *(undefined4 *)(plVar6 + 5) = 0x156;
          plVar10 = (longlong *)FUN_23e914090(param_1,plVar13,plVar16);
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          if (plVar10 != (longlong *)0x0) {
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            plVar13 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23ee29220);
            if (plVar13 == (longlong *)0x0) {
              plStack_90 = *(longlong **)(param_1 + 0x60);
              plVar11 = *(longlong **)(param_1 + 0x70);
              plVar10 = (longlong *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar15 = 0x159;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar13 = DAT_23ed6a4f8;
              uVar7 = *(undefined8 *)(param_1 + 0x68);
              goto joined_r0x00023c61c0df;
            }
            *(undefined4 *)(plVar6 + 5) = 0x159;
            plVar10 = (longlong *)FUN_23e91bfe0(param_1,plVar13,_DAT_23ee29508);
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            if (plVar10 == (longlong *)0x0) {
              plStack_90 = *(longlong **)(param_1 + 0x60);
              plVar11 = *(longlong **)(param_1 + 0x70);
              uVar15 = 0x159;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar13 = DAT_23ed6a4f8;
              uVar7 = *(undefined8 *)(param_1 + 0x68);
              goto joined_r0x00023c61c0df;
            }
            param_4 = (longlong *)FUN_23e8bc2f0(plVar10,_DAT_23ee29510);
            if (param_4 != (longlong *)0x0) {
              *(undefined4 *)(plVar6 + 5) = 0x15a;
              plVar13 = (longlong *)FUN_23e91bfe0(param_1,plVar10,_DAT_23ee29518);
              if (plVar13 == (longlong *)0x0) goto LAB_23c61c5e8;
              *(undefined4 *)(plVar6 + 5) = 0x15a;
              plVar14 = (longlong *)FUN_23e914090(param_1,param_4,plVar13);
              *param_4 = *param_4 + -1;
              if (*param_4 == 0) {
                (**(code **)(param_4[1] + 0x30))(param_4);
              }
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                (**(code **)(plVar13[1] + 0x30))(plVar13);
              }
              if (plVar14 != (longlong *)0x0) {
                *plVar14 = *plVar14 + -1;
                if (*plVar14 == 0) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                }
                lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                plVar6 = *(longlong **)(lVar9 + 0x28);
                plVar12 = (longlong *)plVar6[2];
                *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
                *(undefined4 *)(plVar6 + 8) = 0xffffffff;
                if (plVar12 != (longlong *)0x0) {
                  plVar6[2] = 0;
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))();
                  }
                }
                *plVar6 = *plVar6 + -1;
                if (*plVar6 == 0) {
                  (**(code **)(plVar6[1] + 0x30))(plVar6);
                }
                plVar6[0xf] = 0;
                pcVar8 = _Py_NoneStruct_exref;
                *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                *plVar16 = *plVar16 + -1;
                if (*plVar16 == 0) {
                  (**(code **)(plVar16[1] + 0x30))(plVar16);
                }
                *plVar10 = *plVar10 + -1;
                if (*plVar10 == 0) {
                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                }
                *plVar2 = *plVar2 + -1;
                if (*plVar2 == 0) {
                  (**(code **)(plVar2[1] + 0x30))(plVar2);
                }
                lVar9 = *plVar1;
                *plVar1 = lVar9 + -1;
                if (lVar9 + -1 == 0) {
                  (**(code **)(plVar1[1] + 0x30))(plVar1);
                }
                *plVar3 = *plVar3 + -1;
                if (*plVar3 != 0) {
                  return pcVar8;
                }
                (**(code **)(plVar3[1] + 0x30))(plVar3);
                return pcVar8;
              }
            }
            plStack_90 = *(longlong **)(param_1 + 0x60);
            plVar11 = *(longlong **)(param_1 + 0x70);
            uVar15 = 0x15a;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar13 = DAT_23ed6a4f8;
            uVar7 = *(undefined8 *)(param_1 + 0x68);
            goto joined_r0x00023c61c0df;
          }
        }
        plVar10 = (longlong *)0x0;
        plStack_90 = *(longlong **)(param_1 + 0x60);
        plVar11 = *(longlong **)(param_1 + 0x70);
        uVar15 = 0x156;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar13 = DAT_23ed6a4f8;
        uVar7 = *(undefined8 *)(param_1 + 0x68);
        goto joined_r0x00023c61c0df;
      }
    }
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar11 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar7 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    uVar15 = 0x155;
    plVar10 = (longlong *)0x0;
    plVar16 = (longlong *)0x0;
    plVar13 = DAT_23ed6a4f8;
  }
joined_r0x00023c61c0df:
  DAT_23ed6a4f8 = plVar13;
  if (plVar11 == (longlong *)0x0) {
    if (plVar13 == (longlong *)0x0) {
      plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar13;
      *plVar13 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar8 = _PyRuntime_exref;
    plVar13[2] = 0;
    plVar13[3] = (longlong)plVar6;
    *plVar6 = *plVar6 + 1;
    lVar9 = *(longlong *)(pcVar8 + 0x1f8);
    *(undefined4 *)((longlong)plVar13 + 0x24) = uVar15;
    lVar9 = *(longlong *)(lVar9 + 0x10);
    *(undefined4 *)(plVar13 + 4) = 0xffffffff;
    lVar9 = *(longlong *)(lVar9 + 0x2e8);
    lVar4 = plVar13[-1];
    puVar5 = *(undefined8 **)(lVar9 + 8);
    *puVar5 = plVar13 + -2;
    plVar13[-2] = lVar9;
    plVar13[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar9 + 8) = plVar13 + -2;
    plVar14 = plVar13;
  }
  else {
    plVar14 = plVar11;
    if ((longlong *)plVar11[3] != plVar6) {
      if (plVar13 == (longlong *)0x0) {
        plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar13;
        *plVar13 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar13[3] = (longlong)plVar6;
      *plVar6 = *plVar6 + 1;
      *(undefined4 *)((longlong)plVar13 + 0x24) = uVar15;
      pcVar8 = _PyRuntime_exref;
      *(undefined4 *)(plVar13 + 4) = 0xffffffff;
      lVar9 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar8 + 0x1f8) + 0x10) + 0x2e8);
      lVar4 = plVar13[-1];
      puVar5 = *(undefined8 **)(lVar9 + 8);
      *puVar5 = plVar13 + -2;
      plVar13[-2] = lVar9;
      plVar13[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar5;
      lVar4 = *plVar11;
      *(longlong **)(lVar9 + 8) = plVar13 + -2;
      plVar13[2] = (longlong)plVar11;
      plVar14 = plVar13;
      if (lVar4 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
    }
  }
  FUN_23e8bba40(plVar6,"oooooo",plVar2,plVar1,plVar3,plVar12,plVar16,plVar10);
  if (_DAT_23ee29ea8 == plVar6) {
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
    _DAT_23ee29ea8 = (longlong *)0x0;
  }
  lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar6 = *(longlong **)(lVar9 + 0x28);
  plVar11 = (longlong *)plVar6[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
  *(undefined4 *)(plVar6 + 8) = 0xffffffff;
  if (plVar11 != (longlong *)0x0) {
    plVar6[2] = 0;
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))();
    }
  }
  *plVar6 = *plVar6 + -1;
  if (*plVar6 == 0) {
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  plVar6[0xf] = 0;
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
    (**(code **)(plVar16[1] + 0x30))(plVar16);
  }
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  lVar9 = *plVar1;
  *plVar1 = lVar9 + -1;
  if (lVar9 + -1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  FUN_23a33aa70(param_1,plStack_90,uVar7,plVar14);
  return (code *)0x0;
}
