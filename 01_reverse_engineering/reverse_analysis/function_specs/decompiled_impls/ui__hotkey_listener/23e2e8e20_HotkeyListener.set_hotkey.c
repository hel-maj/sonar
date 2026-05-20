/* ===== 23e2e8e20 ui.hotkey_listener:69 ===== */
/* ghidra_name=FUN_23e2e8e20 entry=23e2e8e20 size=4077 */

longlong * FUN_23e2e8e20(longlong param_1,undefined8 param_2,longlong *param_3)

{
  longlong lVar1;
  int iVar2;
  longlong *plVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  longlong *plVar7;
  char cVar8;
  int iVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  code *pcVar15;
  longlong lVar16;
  longlong *plVar17;
  longlong lVar18;
  undefined4 uVar19;
  code *pcVar20;
  longlong *plVar21;
  longlong local_80;
  undefined8 local_78;
  undefined1 local_68 [16];
  longlong *local_58;
  
  plVar17 = DAT_23eeb0140;
  plVar3 = (longlong *)*param_3;
  plVar4 = (longlong *)param_3[1];
  local_58 = (longlong *)0x0;
  local_68 = (undefined1  [16])0x0;
  if (DAT_23eeb0140 != (longlong *)0x0) {
    lVar16 = *DAT_23eeb0140;
    if (lVar16 < 2) {
      if (DAT_23eeb0140[2] == 0) goto LAB_23e2e8ea6;
      *DAT_23eeb0140 = lVar16 + -1;
      if (lVar16 + -1 == 0) {
        (**(code **)(plVar17[1] + 0x30))(plVar17);
      }
    }
    else {
      *DAT_23eeb0140 = lVar16 + -1;
    }
  }
  DAT_23eeb0140 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeb0138,DAT_23eeb0170);
LAB_23e2e8ea6:
  plVar21 = DAT_23eeb0140;
  lVar16 = *(longlong *)(param_1 + 0x38);
  plVar17 = DAT_23eeb0140 + 9;
  lVar18 = *(longlong *)(lVar16 + 8);
  DAT_23eeb0140[0xf] = lVar18;
  *(longlong **)(lVar16 + 8) = plVar17;
  if ((lVar18 != 0) &&
     (((*(char *)(lVar18 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar18 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar18 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar18 + 0x38))) && (plVar21[0xe] != 0)))) {
    plVar17 = *(longlong **)(lVar18 + 0x28);
    *(longlong **)(plVar21[0xe] + 0x10) = plVar17;
    if (plVar17 != (longlong *)0x0) {
      *plVar17 = *plVar17 + 1;
    }
  }
  *plVar21 = *plVar21 + 1;
  *(undefined4 *)(plVar21 + 8) = 0;
  iVar9 = FUN_23a35f020(plVar4);
  if (iVar9 == -1) {
    local_80 = *(longlong *)(param_1 + 0x60);
    local_58 = *(longlong **)(param_1 + 0x70);
    pcVar20 = (code *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar11 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    plVar17 = (longlong *)0x0;
    uVar19 = 0x47;
    local_78 = *(undefined8 *)(param_1 + 0x68);
    local_68._8_8_ = local_78;
    local_68._0_8_ = local_80;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  else {
    lVar16 = *(longlong *)(param_1 + 0x10);
    iVar2 = *(int *)(lVar16 + 0x1188);
    if (iVar9 == 0) {
      if (iVar2 == 0) {
        plVar17 = (longlong *)FUN_23a33a530(PyList_Type_exref);
      }
      else {
        *(int *)(lVar16 + 0x1188) = iVar2 + -1;
        plVar17 = *(longlong **)(lVar16 + 0xf08 + (longlong)(iVar2 + -1) * 8);
        *plVar17 = 1;
      }
      pcVar15 = _PyRuntime_exref;
      pcVar20 = (code *)0x0;
      plVar11 = (longlong *)0x0;
      plVar17[2] = 0;
      plVar10 = (longlong *)0x0;
      plVar17[4] = 0;
      lVar16 = *(longlong *)(pcVar15 + 0x1f8);
      plVar17[3] = 0;
      lVar16 = *(longlong *)(*(longlong *)(lVar16 + 0x10) + 0x2e8);
      lVar18 = plVar17[-1];
      puVar5 = *(undefined8 **)(lVar16 + 8);
      *puVar5 = plVar17 + -2;
      plVar17[-2] = lVar16;
      plVar17[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar5;
      *(longlong **)(lVar16 + 8) = plVar17 + -2;
      plVar21 = (longlong *)0x0;
LAB_23e2e8fb3:
      lVar16 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
      plVar12 = *(longlong **)(lVar16 + 0x28);
      plVar13 = (longlong *)plVar12[2];
      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar16 + 0x30);
      *(undefined4 *)(plVar12 + 8) = 0xffffffff;
      if (plVar13 != (longlong *)0x0) {
        plVar12[2] = 0;
        *plVar13 = *plVar13 + -1;
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))();
        }
      }
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      plVar12[0xf] = 0;
      if ((plVar21 != (longlong *)0x0) && (*plVar21 = *plVar21 + -1, *plVar21 == 0)) {
        (**(code **)(plVar21[1] + 0x30))(plVar21);
      }
      if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      if ((pcVar20 != (code *)0x0) &&
         (*(longlong *)pcVar20 = *(longlong *)pcVar20 + -1, *(longlong *)pcVar20 == 0)) {
        (**(code **)(*(longlong *)(pcVar20 + 8) + 0x30))(pcVar20);
      }
      lVar16 = *plVar3;
      *plVar3 = lVar16 + -1;
      if (lVar16 + -1 == 0) {
        (**(code **)(plVar3[1] + 0x30))(plVar3);
      }
      lVar16 = *plVar4;
      *plVar4 = lVar16 + -1;
      if (lVar16 + -1 != 0) {
        return plVar17;
      }
      (**(code **)(plVar4[1] + 0x30))(plVar4);
      return plVar17;
    }
    if (iVar2 == 0) {
      plVar17 = (longlong *)FUN_23a33a530(PyList_Type_exref);
    }
    else {
      *(int *)(lVar16 + 0x1188) = iVar2 + -1;
      plVar17 = *(longlong **)(lVar16 + 0xf08 + (longlong)(iVar2 + -1) * 8);
      *plVar17 = 1;
    }
    pcVar20 = _PyRuntime_exref;
    plVar17[2] = 0;
    plVar17[4] = 0;
    lVar16 = *(longlong *)(pcVar20 + 0x1f8);
    plVar17[3] = 0;
    lVar16 = *(longlong *)(*(longlong *)(lVar16 + 0x10) + 0x2e8);
    lVar18 = plVar17[-1];
    puVar5 = *(undefined8 **)(lVar16 + 8);
    *puVar5 = plVar17 + -2;
    plVar17[-2] = lVar16;
    plVar17[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar16 + 8) = plVar17 + -2;
    plVar10 = (longlong *)FUN_23e8bc2f0(plVar4,DAT_23ed6d020);
    if (plVar10 == (longlong *)0x0) {
      local_80 = *(longlong *)(param_1 + 0x60);
      local_58 = *(longlong **)(param_1 + 0x70);
      pcVar20 = (code *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar11 = (longlong *)0x0;
      uVar19 = 0x4a;
      local_78 = *(undefined8 *)(param_1 + 0x68);
      local_68._8_8_ = local_78;
      local_68._0_8_ = local_80;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar10 = (longlong *)0x0;
    }
    else {
      *(undefined4 *)(plVar21 + 5) = 0x4a;
      plVar11 = (longlong *)FUN_23e94bb80(param_1,plVar10,DAT_23eead118);
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if (plVar11 == (longlong *)0x0) {
        local_80 = *(longlong *)(param_1 + 0x60);
        local_58 = *(longlong **)(param_1 + 0x70);
        pcVar20 = (code *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar10 = (longlong *)0x0;
        uVar19 = 0x4a;
        local_78 = *(undefined8 *)(param_1 + 0x68);
        local_68._8_8_ = local_78;
        local_68._0_8_ = local_80;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar11 = (longlong *)0x0;
      }
      else {
        plVar12 = (longlong *)FUN_23ebf7180(plVar11);
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        pcVar20 = (code *)0x0;
        plVar10 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        if (plVar12 == (longlong *)0x0) {
          local_80 = *(longlong *)(param_1 + 0x60);
          local_58 = *(longlong **)(param_1 + 0x70);
          plVar11 = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar10 = (longlong *)0x0;
          uVar19 = 0x4a;
          local_78 = *(undefined8 *)(param_1 + 0x68);
          local_68._8_8_ = local_78;
          local_68._0_8_ = local_80;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        }
        else {
          do {
            pcVar15 = *(code **)(plVar12[1] + 0xe0);
            if (pcVar15 == (code *)0x0) {
              PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,"\'%s\' object is not an iterator",
                           *(undefined8 *)(plVar12[1] + 0x18));
LAB_23e2e9972:
              cVar8 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
              if (cVar8 == '\0') {
                local_80 = *(longlong *)(param_1 + 0x60);
                plVar13 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                local_78 = *(undefined8 *)(param_1 + 0x68);
                local_58 = (longlong *)0x0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                local_68 = (undefined1  [16])0x0;
                if (plVar10 != (longlong *)0x0) {
                  uVar19 = 0x4a;
                  goto LAB_23e2e94da;
                }
                plVar10 = (longlong *)0x0;
                uVar19 = 0x4a;
                goto LAB_23e2e94f2;
              }
              if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
              lVar16 = *plVar12;
              *plVar12 = lVar16 + -1;
              if (lVar16 + -1 == 0) {
                (**(code **)(plVar12[1] + 0x30))(plVar12);
              }
              *plVar17 = *plVar17 + 1;
              plVar21 = plVar17;
              goto LAB_23e2e8fb3;
            }
            plVar13 = (longlong *)(*pcVar15)(plVar12);
            if (plVar13 == (longlong *)0x0) goto LAB_23e2e9972;
            if (plVar10 == (longlong *)0x0) {
              *plVar13 = *plVar13 + 1;
            }
            else {
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
                lVar16 = *plVar13;
              }
              else {
                lVar16 = *plVar13;
              }
              *plVar13 = lVar16 + 1;
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
            }
            plVar14 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23eead120);
            plVar10 = plVar13;
            if (plVar14 == (longlong *)0x0) {
LAB_23e2e9b10:
              local_80 = *(longlong *)(param_1 + 0x60);
              plVar13 = *(longlong **)(param_1 + 0x70);
              uVar19 = 0x4b;
              *(undefined8 *)(param_1 + 0x70) = 0;
              local_78 = *(undefined8 *)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23e2e94da;
            }
            *(undefined4 *)(plVar21 + 5) = 0x4b;
            plVar13 = (longlong *)FUN_23e91a870(param_1,plVar14);
            *plVar14 = *plVar14 + -1;
            if (*plVar14 == 0) {
              (**(code **)(plVar14[1] + 0x30))(plVar14);
            }
            if (plVar13 == (longlong *)0x0) goto LAB_23e2e9b10;
            plVar14 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23eead128);
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            if (plVar14 == (longlong *)0x0) goto LAB_23e2e9b10;
            *(undefined4 *)(plVar21 + 5) = 0x4b;
            plVar13 = (longlong *)FUN_23e91a870(param_1,plVar14);
            *plVar14 = *plVar14 + -1;
            if (*plVar14 == 0) {
              (**(code **)(plVar14[1] + 0x30))(plVar14);
            }
            if (plVar13 == (longlong *)0x0) goto LAB_23e2e9b10;
            if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            lVar16 = *(longlong *)(DAT_23eead080 + 0x20);
            plVar11 = plVar13;
            if (*(char *)(lVar16 + 10) == '\0') {
              plVar14 = (longlong *)FUN_23a37a020(DAT_23eead080,DAT_23eead130);
              if (plVar14 == (longlong *)0x0) goto LAB_23e2e9479;
              lVar18 = *plVar14;
LAB_23e2e9a08:
              if (lVar18 == 0) goto LAB_23e2e9479;
            }
            else {
              iVar9 = *(int *)(lVar16 + 0xc);
              if (*(int *)(lVar16 + 0xc) == 0) {
                *(int *)(lVar16 + 0xc) = DAT_23ec14e3c;
                iVar9 = DAT_23ec14e3c;
                DAT_23ec14e3c = DAT_23ec14e3c + 1;
              }
              if (DAT_23ec14e40 != iVar9) {
                DAT_23ec14e40 = iVar9;
                DAT_23eeb0130 =
                     FUN_23e8cbd60(lVar16,DAT_23eead130,*(undefined8 *)(DAT_23eead130 + 0x18));
              }
              if (-1 < DAT_23eeb0130) {
                lVar1 = lVar16 + 0x20 + (1L << (*(byte *)(lVar16 + 9) & 0x3f));
                lVar18 = *(longlong *)(lVar1 + 8 + DAT_23eeb0130 * 0x10);
                if (lVar18 != 0) goto LAB_23e2e9337;
                DAT_23eeb0130 =
                     FUN_23e8cbd60(lVar16,DAT_23eead130,*(undefined8 *)(DAT_23eead130 + 0x18));
                if (-1 < DAT_23eeb0130) {
                  lVar18 = *(longlong *)(lVar1 + 8 + DAT_23eeb0130 * 0x10);
                  goto LAB_23e2e9a08;
                }
              }
LAB_23e2e9479:
              plVar14 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eead130);
              if ((plVar14 == (longlong *)0x0) || (lVar18 = *plVar14, lVar18 == 0)) {
                FUN_23e915740(param_1,local_68,DAT_23eead130);
                uVar19 = 0x4c;
                local_80 = local_68._0_8_;
                local_78 = local_68._8_8_;
                plVar13 = local_58;
                goto LAB_23e2e94da;
              }
            }
LAB_23e2e9337:
            plVar14 = (longlong *)FUN_23e8bc2f0(lVar18,DAT_23ed6ce40);
            if (plVar14 == (longlong *)0x0) {
LAB_23e2e9d50:
              local_80 = *(longlong *)(param_1 + 0x60);
              uVar19 = 0x4c;
              plVar13 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              local_78 = *(undefined8 *)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23e2e94da;
            }
            *(undefined4 *)(plVar21 + 5) = 0x4c;
            pcVar15 = (code *)FUN_23e914090(param_1,plVar14,plVar13);
            *plVar14 = *plVar14 + -1;
            if (*plVar14 == 0) {
              (**(code **)(plVar14[1] + 0x30))(plVar14);
            }
            if (pcVar15 == (code *)0x0) goto LAB_23e2e9d50;
            if ((pcVar20 != (code *)0x0) &&
               (*(longlong *)pcVar20 = *(longlong *)pcVar20 + -1, *(longlong *)pcVar20 == 0)) {
              (**(code **)(*(longlong *)(pcVar20 + 8) + 0x30))(pcVar20);
            }
            if (pcVar15 == _Py_NoneStruct_exref) {
              plVar14 = (longlong *)FUN_23e8bd600(param_1,plVar13);
              if (plVar14 == (longlong *)0x0) {
                local_80 = *(longlong *)(param_1 + 0x60);
                plVar13 = *(longlong **)(param_1 + 0x70);
                uVar19 = 0x4d;
                *(undefined8 *)(param_1 + 0x70) = 0;
                local_78 = *(undefined8 *)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                pcVar20 = pcVar15;
                goto LAB_23e2e94da;
              }
              lVar16 = *plVar14 + -1;
              if ((plVar14[2] == 1) && ((int)plVar14[3] == 1)) {
                *plVar14 = lVar16;
                if (lVar16 == 0) {
                  (**(code **)(plVar14[1] + 0x30))();
                }
                pcVar15 = (code *)FUN_23e8bc930(plVar13);
                pcVar20 = _Py_NoneStruct_exref;
                if (pcVar15 == (code *)0x0) {
                  local_80 = *(longlong *)(param_1 + 0x60);
                  uVar19 = 0x4e;
                  plVar13 = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  local_78 = *(undefined8 *)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e2e94da;
                }
                lVar16 = *(longlong *)_Py_NoneStruct_exref;
                *(longlong *)_Py_NoneStruct_exref = lVar16 + -1;
                if (lVar16 + -1 == 0) {
                  (**(code **)(*(longlong *)(pcVar20 + 8) + 0x30))(pcVar20);
                }
              }
              else {
                *plVar14 = lVar16;
                if (lVar16 == 0) {
                  (**(code **)(plVar14[1] + 0x30))();
                }
              }
            }
            iVar9 = FUN_23a35f020(pcVar15);
            pcVar20 = pcVar15;
            if (iVar9 == -1) {
              local_80 = *(longlong *)(param_1 + 0x60);
              uVar19 = 0x4f;
              plVar13 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              local_78 = *(undefined8 *)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23e2e94da;
            }
            if (iVar9 != 0) {
              FUN_23e8bc550(plVar17,pcVar15);
            }
            lVar16 = *(longlong *)(param_1 + 0x10);
            if ((((*(int *)(*(longlong *)(lVar16 + 0x28) + 0x160) != 0) ||
                 (*(int *)(lVar16 + 0x78) != 0)) && (iVar9 = Py_MakePendingCalls(), iVar9 < 0)) &&
               (local_80 = *(longlong *)(param_1 + 0x60), local_80 != 0)) goto LAB_23e2e97f2;
            if (*(int *)(lVar16 + 0x68) == 0) {
              plVar13 = *(longlong **)(param_1 + 0x90);
            }
            else {
              PyEval_SaveThread();
              PyEval_AcquireThread(param_1);
              plVar13 = *(longlong **)(param_1 + 0x90);
            }
          } while (plVar13 == (longlong *)0x0);
          plVar14 = *(longlong **)(param_1 + 0x60);
          plVar6 = *(longlong **)(param_1 + 0x68);
          *(undefined8 *)(param_1 + 0x90) = 0;
          plVar7 = *(longlong **)(param_1 + 0x70);
          *(longlong **)(param_1 + 0x60) = plVar13;
          *plVar13 = *plVar13 + 1;
          *(undefined8 *)(param_1 + 0x68) = 0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
            (**(code **)(plVar14[1] + 0x30))();
          }
          if ((plVar6 != (longlong *)0x0) && (*plVar6 = *plVar6 + -1, *plVar6 == 0)) {
            (**(code **)(plVar6[1] + 0x30))(plVar6);
          }
          if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
            (**(code **)(plVar7[1] + 0x30))(plVar7);
          }
          local_80 = *(longlong *)(param_1 + 0x60);
LAB_23e2e97f2:
          local_78 = *(undefined8 *)(param_1 + 0x68);
          plVar13 = *(longlong **)(param_1 + 0x70);
          uVar19 = 0x4a;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e2e94da:
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
LAB_23e2e94f2:
          lVar16 = *plVar12;
          *plVar12 = lVar16 + -1;
          if (lVar16 + -1 == 0) {
            (**(code **)(plVar12[1] + 0x30))();
          }
          local_68._8_8_ = local_78;
          local_68._0_8_ = local_80;
          local_58 = plVar13;
        }
      }
    }
  }
  plVar13 = local_58;
  plVar12 = DAT_23ed6a4f8;
  if (local_58 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar13 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar13;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar15 = _PyRuntime_exref;
    plVar12[2] = 0;
    plVar12[3] = (longlong)plVar21;
    *plVar21 = *plVar21 + 1;
    lVar16 = *(longlong *)(pcVar15 + 0x1f8);
    *(undefined4 *)((longlong)plVar12 + 0x24) = uVar19;
    lVar16 = *(longlong *)(lVar16 + 0x10);
    *(undefined4 *)(plVar12 + 4) = 0xffffffff;
    lVar16 = *(longlong *)(lVar16 + 0x2e8);
    lVar18 = plVar12[-1];
    puVar5 = *(undefined8 **)(lVar16 + 8);
    *puVar5 = plVar12 + -2;
    plVar12[-2] = lVar16;
    plVar12[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar16 + 8) = plVar12 + -2;
    plVar14 = plVar12;
  }
  else {
    plVar14 = local_58;
    if ((longlong *)local_58[3] != plVar21) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar14 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar14;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar12[3] = (longlong)plVar21;
      *plVar21 = *plVar21 + 1;
      *(undefined4 *)((longlong)plVar12 + 0x24) = uVar19;
      pcVar15 = _PyRuntime_exref;
      *(undefined4 *)(plVar12 + 4) = 0xffffffff;
      lVar16 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar15 + 0x1f8) + 0x10) + 0x2e8);
      lVar18 = plVar12[-1];
      puVar5 = *(undefined8 **)(lVar16 + 8);
      *puVar5 = plVar12 + -2;
      plVar12[-2] = lVar16;
      plVar12[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar5;
      lVar18 = *plVar13;
      *(longlong **)(lVar16 + 8) = plVar12 + -2;
      plVar12[2] = (longlong)plVar13;
      plVar14 = plVar12;
      if (lVar18 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
    }
  }
  local_58 = plVar14;
  plVar12 = local_58;
  FUN_23e8bba40(plVar21,"oooooo",plVar3,plVar4,plVar17,plVar10,plVar11,pcVar20);
  if (DAT_23eeb0140 == plVar21) {
    *plVar21 = *plVar21 + -1;
    if (*plVar21 == 0) {
      (**(code **)(plVar21[1] + 0x30))(plVar21);
    }
    DAT_23eeb0140 = (longlong *)0x0;
  }
  lVar16 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar21 = *(longlong **)(lVar16 + 0x28);
  plVar13 = (longlong *)plVar21[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar16 + 0x30);
  *(undefined4 *)(plVar21 + 8) = 0xffffffff;
  if (plVar13 != (longlong *)0x0) {
    plVar21[2] = 0;
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))();
    }
  }
  *plVar21 = *plVar21 + -1;
  if (*plVar21 == 0) {
    (**(code **)(plVar21[1] + 0x30))(plVar21);
  }
  plVar21[0xf] = 0;
  local_58 = (longlong *)0x0;
  local_68 = (undefined1  [16])0x0;
  if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
    (**(code **)(plVar17[1] + 0x30))(plVar17);
  }
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((pcVar20 != (code *)0x0) &&
     (*(longlong *)pcVar20 = *(longlong *)pcVar20 + -1, *(longlong *)pcVar20 == 0)) {
    (**(code **)(*(longlong *)(pcVar20 + 8) + 0x30))(pcVar20);
  }
  lVar16 = *plVar3;
  *plVar3 = lVar16 + -1;
  if (lVar16 + -1 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  lVar16 = *plVar4;
  *plVar4 = lVar16 + -1;
  if (lVar16 + -1 == 0) {
    (**(code **)(plVar4[1] + 0x30))(plVar4);
  }
  FUN_23a33aa70(param_1,local_80,local_78,plVar12);
  return (longlong *)0x0;
}
