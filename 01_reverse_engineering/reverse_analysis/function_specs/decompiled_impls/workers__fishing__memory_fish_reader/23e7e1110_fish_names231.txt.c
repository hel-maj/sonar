/* ===== 23e7e1110 workers.fishing.memory_fish_read:45 ===== */
/* ghidra_name=FUN_23e7e1110 entry=23e7e1110 size=4871 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23e7e1110(longlong param_1)

{
  undefined8 *puVar1;
  longlong *plVar2;
  code *pcVar3;
  longlong *plVar4;
  longlong *plVar5;
  char cVar6;
  int iVar7;
  longlong lVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong lVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong lVar16;
  undefined8 uVar17;
  code *pcVar18;
  code *pcVar19;
  code *pcVar20;
  code *pcVar21;
  longlong lVar22;
  longlong lVar23;
  ulonglong uVar24;
  undefined4 uVar25;
  code *local_b0;
  undefined1 local_98 [16];
  code *local_88 [2];
  code *local_78;
  undefined8 uStack_70;
  code *local_68;
  longlong *local_60;
  
  plVar10 = _DAT_23eedebc8;
  if (_DAT_23eedebc8 == (longlong *)0x0) {
LAB_23e7e1152:
    _DAT_23eedebc8 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedebb8,DAT_23eedebc0,8);
  }
  else {
    lVar8 = *_DAT_23eedebc8;
    if (1 < lVar8) {
      *_DAT_23eedebc8 = lVar8 + -1;
      goto LAB_23e7e1152;
    }
    if (_DAT_23eedebc8[2] != 0) {
      *_DAT_23eedebc8 = lVar8 + -1;
      if (lVar8 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23e7e1152;
    }
  }
  plVar2 = _DAT_23eedebc8;
  lVar8 = *(longlong *)(param_1 + 0x38);
  plVar10 = _DAT_23eedebc8 + 9;
  lVar16 = *(longlong *)(lVar8 + 8);
  _DAT_23eedebc8[0xf] = lVar16;
  *(longlong **)(lVar8 + 8) = plVar10;
  if ((lVar16 != 0) &&
     (((*(char *)(lVar16 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar16 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar16 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar16 + 0x38))) && (plVar2[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar16 + 0x28);
    *(longlong **)(plVar2[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar2 = *plVar2 + 1;
  *(undefined4 *)(plVar2 + 8) = 0;
  lVar8 = FUN_23e8dda40();
  if (lVar8 == 0) {
    uVar25 = 0x2f;
    FUN_23e915740(param_1,&local_78,_DAT_23eeddbc0);
    local_b0 = _PyRuntime_exref;
    plVar10 = (longlong *)0x0;
    pcVar19 = local_68;
    pcVar20 = local_78;
    uVar17 = uStack_70;
  }
  else {
    plVar9 = (longlong *)FUN_23e8bc2f0(lVar8,_DAT_23eeddbc8);
    pcVar19 = _DAT_23eeddbd8;
    uVar17 = _DAT_23eeddbd0;
    plVar10 = (longlong *)0x0;
    if (plVar9 == (longlong *)0x0) {
LAB_23e7e1d40:
      local_b0 = _PyRuntime_exref;
      pcVar20 = *(code **)(param_1 + 0x60);
      uVar25 = 0x2f;
      pcVar19 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar17 = *(undefined8 *)(param_1 + 0x68);
    }
    else {
      lVar8 = FUN_23e8dda40();
      if (lVar8 == 0) {
        FUN_23e915740(param_1,&local_78,_DAT_23eeddbc0);
        *plVar9 = *plVar9 + -1;
        pcVar19 = local_68;
        pcVar20 = local_78;
        uVar17 = uStack_70;
        if (*plVar9 == 0) goto LAB_23e7e1ea3;
LAB_23e7e1f8c:
        plVar10 = (longlong *)0x0;
        uVar25 = 0x33;
        local_b0 = _PyRuntime_exref;
      }
      else {
        plVar10 = (longlong *)FUN_23e8bc2f0(lVar8,_DAT_23eeddbe0);
        lVar8 = _DAT_23eeddbe8;
        if (plVar10 == (longlong *)0x0) {
          pcVar20 = *(code **)(param_1 + 0x60);
          uVar17 = *(undefined8 *)(param_1 + 0x68);
          pcVar19 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar9 = *plVar9 + -1;
          if (*plVar9 != 0) goto LAB_23e7e1f8c;
LAB_23e7e1ea3:
          uVar25 = 0x33;
          plVar10 = (longlong *)0x0;
          (**(code **)(plVar9[1] + 0x30))(plVar9);
          local_b0 = _PyRuntime_exref;
        }
        else {
          lVar22 = 0;
          local_78 = (code *)&DAT_23ec5e3bc;
          lVar16 = *(longlong *)(_DAT_23eeddbe8 + 0x10);
          plVar11 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),lVar16);
          if (0 < lVar16) {
            do {
              lVar12 = FUN_23e971d80(param_1,*(undefined8 *)(lVar8 + 0x18 + lVar22 * 8),&local_78);
              plVar11[lVar22 + 3] = lVar12;
              lVar22 = lVar22 + 1;
            } while (lVar16 != lVar22);
          }
          local_78 = _Py_TrueStruct_exref;
          *(undefined4 *)(plVar2 + 5) = 0x2f;
          uStack_70 = uVar17;
          local_68 = pcVar19;
          local_60 = plVar10;
          plVar13 = (longlong *)FUN_23e9188e0(param_1,plVar9,plVar11,&local_78,_DAT_23eeddbf0);
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          if (plVar13 != (longlong *)0x0) {
            plVar9 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23eeddbf8);
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            if (plVar9 != (longlong *)0x0) {
              *(undefined4 *)(plVar2 + 5) = 0x2f;
              plVar10 = (longlong *)FUN_23e91a870(param_1,plVar9);
              *plVar9 = *plVar9 + -1;
              if (*plVar9 == 0) {
                (**(code **)(plVar9[1] + 0x30))(plVar9);
              }
              if (plVar10 == (longlong *)0x0) goto LAB_23e7e1d40;
              plVar9 = (longlong *)FUN_23e8bc2f0(plVar10,_DAT_23eeddc00);
              if (plVar9 == (longlong *)0x0) {
LAB_23e7e1f10:
                local_b0 = _PyRuntime_exref;
                pcVar19 = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                pcVar20 = *(code **)(param_1 + 0x60);
                uVar17 = *(undefined8 *)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              }
              else {
                *(undefined4 *)(plVar2 + 5) = 0x35;
                plVar11 = (longlong *)FUN_23e91a870(param_1,plVar9);
                *plVar9 = *plVar9 + -1;
                if (*plVar9 == 0) {
                  (**(code **)(plVar9[1] + 0x30))(plVar9);
                }
                if (plVar11 == (longlong *)0x0) goto LAB_23e7e1f10;
                plVar9 = (longlong *)FUN_23ebf7180(plVar11);
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                if (plVar9 == (longlong *)0x0) goto LAB_23e7e1f10;
                lVar8 = *(longlong *)(param_1 + 0x10);
                if (*(int *)(lVar8 + 0x1188) == 0) {
                  plVar11 = (longlong *)FUN_23a33a530(PyList_Type_exref);
                }
                else {
                  iVar7 = *(int *)(lVar8 + 0x1188) + -1;
                  *(int *)(lVar8 + 0x1188) = iVar7;
                  plVar11 = *(longlong **)(lVar8 + 0xf08 + (longlong)iVar7 * 8);
                  *plVar11 = 1;
                }
                local_b0 = _PyRuntime_exref;
                plVar11[2] = 0;
                plVar11[4] = 0;
                lVar8 = *(longlong *)(local_b0 + 0x1f8);
                plVar11[3] = 0;
                lVar8 = *(longlong *)(*(longlong *)(lVar8 + 0x10) + 0x2e8);
                lVar16 = plVar11[-1];
                puVar1 = *(undefined8 **)(lVar8 + 8);
                *puVar1 = plVar11 + -2;
                plVar11[-2] = lVar8;
                plVar11[-1] = (ulonglong)((uint)lVar16 & 3) | (ulonglong)puVar1;
                *(longlong **)(lVar8 + 8) = plVar11 + -2;
                lVar8 = plVar9[1];
                pcVar19 = *(code **)(lVar8 + 0xe0);
                plVar13 = (longlong *)0x0;
                while (pcVar19 != (code *)0x0) {
                  plVar14 = (longlong *)(*pcVar19)(plVar9);
                  if (plVar14 == (longlong *)0x0) goto LAB_23e7e164b;
                  if (plVar13 == (longlong *)0x0) {
                    *plVar14 = *plVar14 + 1;
                  }
                  else {
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                      lVar8 = *plVar14;
                    }
                    else {
                      lVar8 = *plVar14;
                    }
                    *plVar14 = lVar8 + 1;
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                    }
                  }
                  plVar13 = (longlong *)FUN_23e8bc2f0(plVar14,DAT_23eeddbf8);
                  if (plVar13 == (longlong *)0x0) {
LAB_23e7e239b:
                    pcVar20 = *(code **)(param_1 + 0x60);
                    uVar17 = *(undefined8 *)(param_1 + 0x68);
                    pcVar19 = *(code **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e7e2310;
                  }
                  *(undefined4 *)(plVar2 + 5) = 0x35;
                  plVar15 = (longlong *)FUN_23e91a870(param_1,plVar13);
                  *plVar13 = *plVar13 + -1;
                  if (*plVar13 == 0) {
                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                  }
                  if (plVar15 == (longlong *)0x0) goto LAB_23e7e239b;
                  plVar13 = (longlong *)FUN_23e8bc2f0(plVar15,_DAT_23eeddc08);
                  *plVar15 = *plVar15 + -1;
                  if (*plVar15 == 0) {
                    (**(code **)(plVar15[1] + 0x30))(plVar15);
                  }
                  if (plVar13 == (longlong *)0x0) goto LAB_23e7e239b;
                  *(undefined4 *)(plVar2 + 5) = 0x35;
                  plVar15 = (longlong *)FUN_23e91a870(param_1,plVar13);
                  *plVar13 = *plVar13 + -1;
                  if (*plVar13 == 0) {
                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                  }
                  if (plVar15 == (longlong *)0x0) goto LAB_23e7e239b;
                  iVar7 = FUN_23a35f020(plVar15);
                  lVar8 = *plVar15 + -1;
                  if (iVar7 == -1) {
                    pcVar20 = *(code **)(param_1 + 0x60);
                    uVar17 = *(undefined8 *)(param_1 + 0x68);
                    pcVar19 = *(code **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *plVar15 = lVar8;
                    if (lVar8 == 0) {
                      (**(code **)(plVar15[1] + 0x30))(plVar15);
                    }
                    goto LAB_23e7e2310;
                  }
                  *plVar15 = lVar8;
                  if (lVar8 == 0) {
                    (**(code **)(plVar15[1] + 0x30))(plVar15);
                  }
                  if (iVar7 != 0) {
                    lVar8 = PyNumber_Long(plVar14);
                    if (lVar8 == 0) goto LAB_23e7e239b;
                    lVar22 = plVar11[2];
                    lVar12 = plVar11[3];
                    lVar16 = lVar22 + 1;
                    if ((plVar11[4] < lVar16) || (lVar16 < plVar11[4] >> 1)) {
                      if (lVar16 == 0) {
                        lVar23 = 0;
                        uVar24 = 0;
                      }
                      else {
                        uVar24 = lVar22 + 7 + (lVar16 >> 3) & 0xfffffffffffffffc;
                        lVar23 = uVar24 * 8;
                      }
                      lVar12 = (*DAT_23ed6e610)(0,lVar12,lVar23);
                      if (lVar12 == 0) {
                        PyErr_NoMemory();
                        goto LAB_23e7e239b;
                      }
                      plVar11[3] = lVar12;
                      plVar11[2] = lVar16;
                      plVar11[4] = uVar24;
                    }
                    else {
                      plVar11[2] = lVar16;
                    }
                    *(longlong *)(lVar12 + lVar22 * 8) = lVar8;
                  }
                  lVar8 = *(longlong *)(param_1 + 0x10);
                  if (((*(int *)(*(longlong *)(lVar8 + 0x28) + 0x160) != 0) ||
                      (*(int *)(lVar8 + 0x78) != 0)) &&
                     ((iVar7 = Py_MakePendingCalls(), iVar7 < 0 &&
                      (pcVar20 = *(code **)(param_1 + 0x60), pcVar20 != (code *)0x0)))) {
LAB_23e7e22e5:
                    pcVar19 = *(code **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar17 = *(undefined8 *)(param_1 + 0x68);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e7e2310;
                  }
                  if (*(int *)(lVar8 + 0x68) == 0) {
                    plVar13 = *(longlong **)(param_1 + 0x90);
                  }
                  else {
                    PyEval_SaveThread();
                    PyEval_AcquireThread(param_1);
                    plVar13 = *(longlong **)(param_1 + 0x90);
                  }
                  if (plVar13 != (longlong *)0x0) {
                    plVar15 = *(longlong **)(param_1 + 0x60);
                    plVar4 = *(longlong **)(param_1 + 0x68);
                    *(undefined8 *)(param_1 + 0x90) = 0;
                    plVar5 = *(longlong **)(param_1 + 0x70);
                    *(longlong **)(param_1 + 0x60) = plVar13;
                    *plVar13 = *plVar13 + 1;
                    *(undefined8 *)(param_1 + 0x68) = 0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
                      (**(code **)(plVar15[1] + 0x30))();
                    }
                    if ((plVar4 != (longlong *)0x0) && (*plVar4 = *plVar4 + -1, *plVar4 == 0)) {
                      (**(code **)(plVar4[1] + 0x30))(plVar4);
                    }
                    if ((plVar5 != (longlong *)0x0) && (*plVar5 = *plVar5 + -1, *plVar5 == 0)) {
                      (**(code **)(plVar5[1] + 0x30))(plVar5);
                    }
                    pcVar20 = *(code **)(param_1 + 0x60);
                    goto LAB_23e7e22e5;
                  }
                  lVar8 = plVar9[1];
                  plVar13 = plVar14;
                  pcVar19 = *(code **)(lVar8 + 0xe0);
                }
                PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,"\'%s\' object is not an iterator"
                             ,*(undefined8 *)(lVar8 + 0x18));
LAB_23e7e164b:
                cVar6 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
                if (cVar6 != '\0') {
                  *plVar11 = *plVar11 + 1;
                  *plVar9 = *plVar9 + -1;
                  if (*plVar9 == 0) {
                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                  }
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    (**(code **)(plVar11[1] + 0x30))(plVar11);
                  }
                  if (plVar13 != (longlong *)0x0) {
                    lVar8 = *plVar13 + -1;
                    *plVar13 = lVar8;
                    if (lVar8 == 0) {
                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                      lVar8 = *plVar13;
                    }
                    *plVar13 = lVar8 + -1;
                    if (lVar8 + -1 == 0) {
                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                    }
                  }
                  goto LAB_23e7e1c24;
                }
                pcVar20 = *(code **)(param_1 + 0x60);
                uVar17 = *(undefined8 *)(param_1 + 0x68);
                pcVar19 = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plVar14 = plVar13;
LAB_23e7e2310:
                *plVar9 = *plVar9 + -1;
                if (*plVar9 == 0) {
                  (**(code **)(plVar9[1] + 0x30))(plVar9);
                }
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                if (plVar14 != (longlong *)0x0) {
                  lVar8 = *plVar14 + -1;
                  *plVar14 = lVar8;
                  if (lVar8 == 0) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                    lVar8 = *plVar14;
                  }
                  *plVar14 = lVar8 + -1;
                  if (lVar8 + -1 == 0) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                  }
                }
              }
              uVar25 = 0x35;
              goto LAB_23e7e172d;
            }
          }
          local_b0 = _PyRuntime_exref;
          pcVar19 = *(code **)(param_1 + 0x70);
          pcVar20 = *(code **)(param_1 + 0x60);
          plVar10 = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          uVar25 = 0x2f;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar17 = *(undefined8 *)(param_1 + 0x68);
        }
      }
    }
  }
LAB_23e7e172d:
  plVar9 = *(longlong **)(param_1 + 0x138);
  local_98._8_8_ = uVar17;
  local_98._0_8_ = pcVar20;
  if (plVar9 != (longlong *)0x0) {
    *plVar9 = *plVar9 + 1;
  }
  pcVar20 = DAT_23ed6a4f8;
  local_88[0] = pcVar19;
  if (pcVar19 == (code *)0x0) {
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar20 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar19 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar19;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    *(longlong *)(pcVar20 + 0x10) = 0;
    *(longlong **)(pcVar20 + 0x18) = plVar2;
    *plVar2 = *plVar2 + 1;
    lVar8 = *(longlong *)(local_b0 + 0x1f8);
    *(undefined4 *)(pcVar20 + 0x20) = 0xffffffff;
    lVar8 = *(longlong *)(lVar8 + 0x10);
    *(undefined4 *)(pcVar20 + 0x24) = uVar25;
    lVar8 = *(longlong *)(lVar8 + 0x2e8);
    lVar16 = *(longlong *)(pcVar20 + -8);
    puVar1 = *(undefined8 **)(lVar8 + 8);
    *puVar1 = pcVar20 + -0x10;
    *(longlong *)(pcVar20 + -0x10) = lVar8;
    *(ulonglong *)(pcVar20 + -8) = (ulonglong)((uint)lVar16 & 3) | (ulonglong)puVar1;
    *(code **)(lVar8 + 8) = pcVar20 + -0x10;
    if ((local_88[0] != (code *)0x0) &&
       (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1, *(longlong *)local_88[0] == 0)) {
      (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))(local_88[0]);
    }
  }
  else {
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar20 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar18 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar18;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    *(longlong **)(pcVar20 + 0x18) = plVar2;
    *plVar2 = *plVar2 + 1;
    lVar8 = *(longlong *)(local_b0 + 0x1f8);
    *(undefined4 *)(pcVar20 + 0x20) = 0xffffffff;
    *(undefined4 *)(pcVar20 + 0x24) = uVar25;
    lVar8 = *(longlong *)(*(longlong *)(lVar8 + 0x10) + 0x2e8);
    lVar16 = *(longlong *)(pcVar20 + -8);
    puVar1 = *(undefined8 **)(lVar8 + 8);
    *puVar1 = pcVar20 + -0x10;
    *(longlong *)(pcVar20 + -0x10) = lVar8;
    *(ulonglong *)(pcVar20 + -8) = (ulonglong)((uint)lVar16 & 3) | (ulonglong)puVar1;
    *(code **)(lVar8 + 8) = pcVar20 + -0x10;
    *(code **)(pcVar20 + 0x10) = pcVar19;
    *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
    if ((local_88[0] != (code *)0x0) &&
       (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1, *(longlong *)local_88[0] == 0)) {
      (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))();
    }
  }
  pcVar19 = _Py_NoneStruct_exref;
  local_88[0] = pcVar20;
  if (((code *)local_98._0_8_ != _Py_NoneStruct_exref) && ((code *)local_98._0_8_ != (code *)0x0)) {
    FUN_23e91b1b0(param_1,local_98,local_98 + 8,local_88);
  }
  plVar11 = *(longlong **)(local_98._8_8_ + 0x28);
  if (local_88[0] == pcVar19) {
    pcVar20 = (code *)0x0;
  }
  else {
    pcVar20 = local_88[0];
    if (local_88[0] != (code *)0x0) {
      *(longlong *)local_88[0] = *(longlong *)local_88[0] + 1;
    }
  }
  *(code **)(local_98._8_8_ + 0x28) = pcVar20;
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))();
  }
  plVar11 = *(longlong **)(param_1 + 0x138);
  *(undefined8 *)(param_1 + 0x138) = local_98._8_8_;
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))();
  }
  *(longlong *)local_98._0_8_ = *(longlong *)local_98._0_8_ + -1;
  if (*(longlong *)local_98._0_8_ == 0) {
    (**(code **)(*(longlong *)(local_98._0_8_ + 8) + 0x30))();
  }
  if ((local_88[0] != (code *)0x0) &&
     (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1, *(longlong *)local_88[0] == 0)) {
    (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))();
  }
  pcVar21 = *(code **)(param_1 + 0x138);
  local_88[0] = (code *)0x0;
  local_98 = (undefined1  [16])0x0;
  pcVar20 = *(code **)PyExc_Exception_exref;
  pcVar18 = *(code **)(pcVar21 + 8);
  if ((*(uint *)(*(longlong *)(pcVar20 + 8) + 0xa8) & 0x4000000) == 0) {
    if ((-1 < (int)*(uint *)(*(longlong *)(pcVar20 + 8) + 0xa8)) ||
       (((byte)pcVar20[0xab] & 0x40) == 0)) {
LAB_23e7e1b18:
      plVar2 = *(longlong **)PyExc_TypeError_exref;
      uVar17 = PyUnicode_FromString
                         ("catching classes that do not inherit from BaseException is not allowed");
      plVar11 = *(longlong **)(param_1 + 0x60);
      plVar13 = *(longlong **)(param_1 + 0x68);
      plVar14 = *(longlong **)(param_1 + 0x70);
      *(longlong **)(param_1 + 0x60) = plVar2;
      *plVar2 = *plVar2 + 1;
      *(undefined8 *)(param_1 + 0x68) = uVar17;
      *(undefined8 *)(param_1 + 0x70) = 0;
      if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
        (**(code **)(plVar11[1] + 0x30))();
      }
      if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
LAB_23e7e1b7d:
      lVar8 = *(longlong *)(param_1 + 0x10);
      if (*(int *)(lVar8 + 0x1188) == 0) {
        plVar11 = (longlong *)FUN_23a33a530(PyList_Type_exref);
      }
      else {
        iVar7 = *(int *)(lVar8 + 0x1188) + -1;
        *(int *)(lVar8 + 0x1188) = iVar7;
        plVar11 = *(longlong **)(lVar8 + 0xf08 + (longlong)iVar7 * 8);
        *plVar11 = 1;
      }
      plVar11[2] = 0;
      plVar11[4] = 0;
      lVar8 = *(longlong *)(local_b0 + 0x1f8);
      plVar11[3] = 0;
      lVar8 = *(longlong *)(*(longlong *)(lVar8 + 0x10) + 0x2e8);
      lVar16 = plVar11[-1];
      puVar1 = *(undefined8 **)(lVar8 + 8);
      *puVar1 = plVar11 + -2;
      plVar11[-2] = lVar8;
      plVar11[-1] = (ulonglong)((uint)lVar16 & 3) | (ulonglong)puVar1;
      *(longlong **)(lVar8 + 8) = plVar11 + -2;
      plVar2 = *(longlong **)(param_1 + 0x138);
      *(longlong **)(param_1 + 0x138) = plVar9;
      if ((plVar2 != (longlong *)0x0) && (*plVar2 = *plVar2 + -1, *plVar2 == 0)) {
        (**(code **)(plVar2[1] + 0x30))();
      }
LAB_23e7e1c24:
      lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
      plVar2 = *(longlong **)(lVar8 + 0x28);
      plVar9 = (longlong *)plVar2[2];
      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar8 + 0x30);
      *(undefined4 *)(plVar2 + 8) = 0xffffffff;
      if (plVar9 != (longlong *)0x0) {
        plVar2[2] = 0;
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))();
        }
      }
      *plVar2 = *plVar2 + -1;
      if (*plVar2 == 0) {
        (**(code **)(plVar2[1] + 0x30))(plVar2);
      }
      plVar2[0xf] = 0;
      if (plVar10 == (longlong *)0x0) {
        return plVar11;
      }
      *plVar10 = *plVar10 + -1;
      if (*plVar10 != 0) {
        return plVar11;
      }
      (**(code **)(plVar10[1] + 0x30))(plVar10);
      return plVar11;
    }
    pcVar3 = *(code **)(pcVar18 + 8);
    if ((*(uint *)(pcVar3 + 0xa8) & 0x40000000) == 0) {
      if ((-1 < (int)*(uint *)(pcVar3 + 0xa8)) || (((byte)pcVar18[0xab] & 0x40) == 0))
      goto LAB_23e7e2152;
    }
    else {
      pcVar18 = pcVar3;
      if (-1 < *(int *)(*(longlong *)(pcVar3 + 8) + 0xa8)) {
LAB_23e7e2152:
        if (pcVar20 != pcVar18) goto LAB_23e7e195d;
        goto LAB_23e7e1b7d;
      }
    }
    lVar8 = *(longlong *)(pcVar18 + 0x158);
    if (lVar8 == 0) {
      do {
        if (pcVar20 == pcVar18) goto LAB_23e7e1b7d;
        pcVar18 = *(code **)(pcVar18 + 0x100);
      } while (pcVar18 != (code *)0x0);
      if (pcVar20 == PyBaseObject_Type_exref) goto LAB_23e7e1b7d;
    }
    else {
      if (*(longlong *)(lVar8 + 0x10) < 1) goto LAB_23e7e195d;
      lVar16 = 0;
      do {
        if (pcVar20 == *(code **)(lVar8 + 0x18 + lVar16 * 8)) goto LAB_23e7e1b7d;
        lVar16 = lVar16 + 1;
      } while (*(longlong *)(lVar8 + 0x10) != lVar16);
    }
LAB_23e7e1956:
    pcVar21 = *(code **)(param_1 + 0x138);
  }
  else {
    lVar8 = *(longlong *)(pcVar20 + 0x10);
    if (0 < lVar8) {
      lVar16 = 0;
      do {
        if ((-1 < *(int *)(*(longlong *)(*(longlong *)(pcVar20 + lVar16 * 8 + 0x18) + 8) + 0xa8)) ||
           ((*(byte *)(*(longlong *)(pcVar20 + lVar16 * 8 + 0x18) + 0xab) & 0x40) == 0))
        goto LAB_23e7e1b18;
        lVar16 = lVar16 + 1;
      } while (lVar8 != lVar16);
      lVar16 = 0;
      do {
        iVar7 = FUN_23a35ebd0(param_1,pcVar18,*(undefined8 *)(pcVar20 + lVar16 * 8 + 0x18));
        if (iVar7 != 0) goto LAB_23e7e1b7d;
        lVar16 = lVar16 + 1;
      } while (lVar8 != lVar16);
      goto LAB_23e7e1956;
    }
  }
LAB_23e7e195d:
  if ((pcVar21 == pcVar19) || (pcVar21 == (code *)0x0)) {
    plVar11 = *(longlong **)PyExc_RuntimeError_exref;
    pcVar19 = (code *)PyUnicode_FromString("No active exception to reraise");
    pcVar21 = *(code **)(param_1 + 0x138);
    *plVar11 = *plVar11 + 1;
    *(longlong **)(param_1 + 0x138) = plVar9;
    if ((pcVar21 != (code *)0x0) &&
       (*(longlong *)pcVar21 = *(longlong *)pcVar21 + -1, *(longlong *)pcVar21 == 0)) {
      iVar7 = 0x2e;
LAB_23e7e1ee6:
      (**(code **)(*(longlong *)(pcVar21 + 8) + 0x30))();
      if (iVar7 == 0) goto LAB_23e7e1f00;
    }
    uVar25 = 0x2e;
    pcVar21 = pcVar19;
  }
  else {
    plVar11 = *(longlong **)(pcVar21 + 8);
    pcVar19 = *(code **)(pcVar21 + 0x28);
    *(longlong *)pcVar21 = *(longlong *)pcVar21 + 1;
    *plVar11 = *plVar11 + 1;
    if (pcVar19 != (code *)0x0) {
      *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
      pcVar20 = pcVar19;
      if (*(longlong **)(pcVar19 + 0x18) == plVar2) {
        *(undefined4 *)(plVar2 + 5) = *(undefined4 *)(pcVar19 + 0x24);
        *(longlong **)(param_1 + 0x138) = plVar9;
        *(longlong *)pcVar21 = *(longlong *)pcVar21 + -1;
        if (*(longlong *)pcVar21 != 0) goto LAB_23e7e1a50;
LAB_23e7e1fbc:
        (*(code *)plVar11[6])(pcVar21);
        if (plVar2 == *(longlong **)(pcVar19 + 0x18)) goto LAB_23e7e1a50;
      }
      else {
        *(longlong **)(param_1 + 0x138) = plVar9;
        *(longlong *)pcVar21 = *(longlong *)pcVar21 + -1;
        if (*(longlong *)pcVar21 == 0) goto LAB_23e7e1fbc;
      }
      pcVar20 = DAT_23ed6a4f8;
      lVar8 = plVar2[5];
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar20 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar18 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar18;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      *(longlong **)(pcVar20 + 0x18) = plVar2;
      *plVar2 = *plVar2 + 1;
      lVar16 = *(longlong *)(local_b0 + 0x1f8);
      *(undefined4 *)(pcVar20 + 0x20) = 0xffffffff;
      *(int *)(pcVar20 + 0x24) = (int)lVar8;
      lVar8 = *(longlong *)(*(longlong *)(lVar16 + 0x10) + 0x2e8);
      lVar16 = *(longlong *)(pcVar20 + -8);
      puVar1 = *(undefined8 **)(lVar8 + 8);
      *puVar1 = pcVar20 + -0x10;
      *(longlong *)(pcVar20 + -0x10) = lVar8;
      *(ulonglong *)(pcVar20 + -8) = (ulonglong)((uint)lVar16 & 3) | (ulonglong)puVar1;
      lVar16 = *(longlong *)pcVar19;
      *(code **)(lVar8 + 8) = pcVar20 + -0x10;
      *(code **)(pcVar20 + 0x10) = pcVar19;
      if (lVar16 == 0) {
        (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))(pcVar19);
      }
      goto LAB_23e7e1a50;
    }
    *(longlong **)(param_1 + 0x138) = plVar9;
    iVar7 = 0;
    *(longlong *)pcVar21 = *(longlong *)pcVar21 + -1;
    pcVar19 = pcVar21;
    if (*(longlong *)pcVar21 == 0) goto LAB_23e7e1ee6;
LAB_23e7e1f00:
    uVar25 = (undefined4)plVar2[5];
    pcVar21 = pcVar19;
  }
  pcVar20 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar20 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    pcVar19 = *(code **)DAT_23ed6a4f8;
    *(longlong *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar19;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  *(longlong *)(pcVar20 + 0x10) = 0;
  *(longlong **)(pcVar20 + 0x18) = plVar2;
  *plVar2 = *plVar2 + 1;
  lVar8 = *(longlong *)(local_b0 + 0x1f8);
  *(undefined4 *)(pcVar20 + 0x20) = 0xffffffff;
  lVar8 = *(longlong *)(lVar8 + 0x10);
  *(undefined4 *)(pcVar20 + 0x24) = uVar25;
  lVar8 = *(longlong *)(lVar8 + 0x2e8);
  lVar16 = *(longlong *)(pcVar20 + -8);
  puVar1 = *(undefined8 **)(lVar8 + 8);
  *puVar1 = pcVar20 + -0x10;
  *(longlong *)(pcVar20 + -0x10) = lVar8;
  *(ulonglong *)(pcVar20 + -8) = (ulonglong)((uint)lVar16 & 3) | (ulonglong)puVar1;
  *(code **)(lVar8 + 8) = pcVar20 + -0x10;
LAB_23e7e1a50:
  FUN_23e8bba40(plVar2,&DAT_23ec5e2bc,plVar10);
  if (_DAT_23eedebc8 == plVar2) {
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
    _DAT_23eedebc8 = (longlong *)0x0;
  }
  lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar2 = *(longlong **)(lVar8 + 0x28);
  plVar9 = (longlong *)plVar2[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar8 + 0x30);
  *(undefined4 *)(plVar2 + 8) = 0xffffffff;
  if (plVar9 != (longlong *)0x0) {
    plVar2[2] = 0;
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))();
    }
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  plVar2[0xf] = 0;
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  FUN_23a33aa70(param_1,plVar11,pcVar21,pcVar20);
  return (longlong *)0x0;
}
