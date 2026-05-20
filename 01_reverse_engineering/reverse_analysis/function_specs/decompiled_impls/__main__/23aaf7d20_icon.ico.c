/* ===== 23aaf7d20 __main__:51 ===== */
/* ghidra_name=FUN_23aaf7d20 entry=23aaf7d20 size=7023 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23aaf7d20(longlong param_1)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  undefined8 uVar4;
  int iVar5;
  code *pcVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong lVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong lVar14;
  longlong *plVar15;
  code *pcVar16;
  longlong *plVar17;
  code *pcVar18;
  code *pcVar19;
  code *pcVar20;
  undefined4 uVar21;
  code *pcVar22;
  longlong **pplVar23;
  longlong *plStack_d0;
  longlong *plStack_a8;
  code *pcStack_a0;
  undefined1 auStack_98 [16];
  code *apcStack_88 [2];
  longlong *plStack_78;
  code *pcStack_70;
  code *pcStack_68;
  
  plVar7 = DAT_23ed90d08;
  if (DAT_23ed90d08 == (longlong *)0x0) {
LAB_23aaf7d62:
    DAT_23ed90d08 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23ed90d00,DAT_23ed90d18,0x20);
  }
  else {
    lVar9 = *DAT_23ed90d08;
    if (1 < lVar9) {
      *DAT_23ed90d08 = lVar9 + -1;
      goto LAB_23aaf7d62;
    }
    if (DAT_23ed90d08[2] != 0) {
      *DAT_23ed90d08 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      goto LAB_23aaf7d62;
    }
  }
  plVar3 = DAT_23ed90d08;
  lVar9 = *(longlong *)(param_1 + 0x38);
  plVar7 = DAT_23ed90d08 + 9;
  lVar14 = *(longlong *)(lVar9 + 8);
  DAT_23ed90d08[0xf] = lVar14;
  *(longlong **)(lVar9 + 8) = plVar7;
  if ((lVar14 != 0) &&
     (((*(char *)(lVar14 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar14 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar14 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar14 + 0x38))) && (plVar3[0xe] != 0)))) {
    plVar7 = *(longlong **)(lVar14 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar7;
    if (plVar7 != (longlong *)0x0) {
      *plVar7 = *plVar7 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  *(undefined4 *)(plVar3 + 8) = 0;
  if ((DAT_23ed6a210 == 0) &&
     (DAT_23ed6a210 = PyImport_ImportModule(&DAT_23ec31700), DAT_23ed6a210 == 0))
  goto LAB_23aaf856d;
  pcVar20 = _Py_FalseStruct_exref;
  pcVar6 = (code *)FUN_23e8bbbe0(param_1,DAT_23ed6a210,_DAT_23ed8fb88,_Py_FalseStruct_exref);
  if (pcVar6 == (code *)0x0) {
    plStack_d0 = *(longlong **)(param_1 + 0x60);
    pcVar20 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar18 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    pcVar22 = _PyRuntime_exref;
    if (pcVar20 != (code *)0x0) {
      if (plVar3 != *(longlong **)(pcVar20 + 0x18)) {
        plVar8 = (longlong *)0x0;
        plVar7 = (longlong *)0x0;
        uVar21 = 0x38;
        goto LAB_23aaf85e0;
      }
LAB_23aaf8844:
      plVar8 = (longlong *)0x0;
      plVar7 = (longlong *)0x0;
      pcVar16 = pcVar20;
      pcVar19 = pcVar18;
      goto LAB_23aaf8670;
    }
    plVar8 = (longlong *)0x0;
    plVar7 = (longlong *)0x0;
    iVar5 = 0x38;
  }
  else {
    iVar5 = FUN_23a35f020(pcVar6);
    if (iVar5 == -1) {
      plStack_d0 = *(longlong **)(param_1 + 0x60);
      pcVar18 = *(code **)(param_1 + 0x68);
      pcVar20 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(longlong *)pcVar6 = *(longlong *)pcVar6 + -1;
      if (*(longlong *)pcVar6 == 0) {
        (**(code **)(*(longlong *)(pcVar6 + 8) + 0x30))(pcVar6);
      }
      if (pcVar20 != (code *)0x0) {
        plVar7 = *(longlong **)(pcVar20 + 0x18);
joined_r0x00023aaf87f8:
        if (plVar3 == plVar7) {
          plVar8 = (longlong *)0x0;
          plVar7 = (longlong *)0x0;
          pcVar6 = (code *)0x0;
          pcVar16 = pcVar20;
          pcVar19 = pcVar18;
          goto LAB_23aaf8670;
        }
        plVar8 = (longlong *)0x0;
        plVar7 = (longlong *)0x0;
        pcVar6 = (code *)0x0;
        uVar21 = 0x38;
        pcVar22 = _PyRuntime_exref;
        goto LAB_23aaf85e0;
      }
LAB_23aaf88ad:
      plVar8 = (longlong *)0x0;
      plVar7 = (longlong *)0x0;
      pcVar6 = (code *)0x0;
      iVar5 = 0x38;
      pcVar22 = _PyRuntime_exref;
    }
    else {
      if (iVar5 != 1) {
        *(longlong *)pcVar6 = *(longlong *)pcVar6 + -1;
        if (*(longlong *)pcVar6 == 0) {
          (**(code **)(*(longlong *)(pcVar6 + 8) + 0x30))(pcVar6);
        }
        iVar5 = PySequence_Contains(DAT_23ed8fb58,DAT_23ed6cdd0);
        if (iVar5 == -1) {
          plStack_d0 = *(longlong **)(param_1 + 0x60);
          pcVar20 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          pcVar18 = *(code **)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (pcVar20 != (code *)0x0) {
            plVar7 = *(longlong **)(pcVar20 + 0x18);
            goto joined_r0x00023aaf87f8;
          }
          goto LAB_23aaf88ad;
        }
        pcVar6 = pcVar20;
        if (iVar5 == 1) {
          pcVar6 = _Py_TrueStruct_exref;
        }
        *(longlong *)pcVar6 = *(longlong *)pcVar6 + 1;
      }
      iVar5 = FUN_23a35f020(pcVar6);
      pcVar20 = _Py_NoneStruct_exref;
      if (iVar5 == -1) {
        plStack_d0 = *(longlong **)(param_1 + 0x60);
        pcVar20 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar18 = *(code **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar22 = _PyRuntime_exref;
        if (pcVar20 != (code *)0x0) {
          if (*(longlong **)(pcVar20 + 0x18) == plVar3) goto LAB_23aaf8844;
          plVar8 = (longlong *)0x0;
          plVar7 = (longlong *)0x0;
          uVar21 = 0x39;
LAB_23aaf85e0:
          pcVar16 = DAT_23ed6a4f8;
          if (DAT_23ed6a4f8 == (code *)0x0) {
            pcVar16 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
          }
          else {
            pcVar19 = *(code **)DAT_23ed6a4f8;
            *(longlong *)DAT_23ed6a4f8 = 1;
            DAT_23ed6a4f8 = pcVar19;
            DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
          }
          *(longlong **)(pcVar16 + 0x18) = plVar3;
          *plVar3 = *plVar3 + 1;
          lVar9 = *(longlong *)(pcVar22 + 0x1f8);
          *(undefined4 *)(pcVar16 + 0x24) = uVar21;
          lVar9 = *(longlong *)(lVar9 + 0x10);
          *(undefined4 *)(pcVar16 + 0x20) = 0xffffffff;
          lVar9 = *(longlong *)(lVar9 + 0x2e8);
          lVar14 = *(longlong *)(pcVar16 + -8);
          puVar2 = *(undefined8 **)(lVar9 + 8);
          *puVar2 = pcVar16 + -0x10;
          *(longlong *)(pcVar16 + -0x10) = lVar9;
          *(ulonglong *)(pcVar16 + -8) = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar2;
          lVar14 = *(longlong *)pcVar20;
          *(code **)(lVar9 + 8) = pcVar16 + -0x10;
          *(code **)(pcVar16 + 0x10) = pcVar20;
          pcVar19 = pcVar18;
          if (lVar14 == 0) {
            (**(code **)(*(longlong *)(pcVar20 + 8) + 0x30))(pcVar20);
          }
          goto LAB_23aaf8670;
        }
        plVar8 = (longlong *)0x0;
        plVar7 = (longlong *)0x0;
        iVar5 = 0x39;
      }
      else {
        if (iVar5 == 0) {
          lVar9 = *(longlong *)(param_1 + 0x38);
          lVar14 = *(longlong *)(lVar9 + 8);
          *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
          plVar7 = *(longlong **)(lVar14 + 0x28);
          plVar3 = (longlong *)plVar7[2];
          *(undefined8 *)(lVar9 + 8) = *(undefined8 *)(lVar14 + 0x30);
          *(undefined4 *)(plVar7 + 8) = 0xffffffff;
          if (plVar3 != (longlong *)0x0) {
            plVar7[2] = 0;
            *plVar3 = *plVar3 + -1;
            if (*plVar3 == 0) {
              (**(code **)(plVar3[1] + 0x30))();
            }
          }
          *plVar7 = *plVar7 + -1;
          if (*plVar7 == 0) {
            (**(code **)(plVar7[1] + 0x30))(plVar7);
          }
          plVar7[0xf] = 0;
          *(longlong *)pcVar6 = *(longlong *)pcVar6 + -1;
          if (*(longlong *)pcVar6 == 0) {
            (**(code **)(*(longlong *)(pcVar6 + 8) + 0x30))(pcVar6);
            return pcVar20;
          }
          return pcVar20;
        }
        if ((DAT_23ed6a210 == 0) &&
           (DAT_23ed6a210 = PyImport_ImportModule(&DAT_23ec31700), DAT_23ed6a210 == 0)) {
          DAT_23ed6a210 = 0;
LAB_23aaf856d:
          FUN_23e9364c0("%s : %s\n","IMPORT_HARD_SYS",
                        "\"Unexpected failure of hard import of \'sys\'\"");
                    /* WARNING: Subroutine does not return */
          abort();
        }
        plVar7 = (longlong *)FUN_23e8bc2f0(DAT_23ed6a210,_DAT_23ed8fb78);
        if (plVar7 == (longlong *)0x0) {
          plStack_d0 = *(longlong **)(param_1 + 0x60);
          pcVar20 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          pcVar18 = *(code **)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          pcVar22 = _PyRuntime_exref;
          if (pcVar20 == (code *)0x0) {
            plVar8 = (longlong *)0x0;
            iVar5 = 0x3d;
            goto LAB_23aaf88c8;
          }
          if (plVar3 != *(longlong **)(pcVar20 + 0x18)) {
            plVar8 = (longlong *)0x0;
            uVar21 = 0x3d;
            goto LAB_23aaf85e0;
          }
LAB_23aaf8f60:
          plVar8 = (longlong *)0x0;
          pcVar16 = pcVar20;
          pcVar19 = pcVar18;
          goto LAB_23aaf8670;
        }
        iVar5 = PySequence_Contains(plVar7,_DAT_23ed8fb90);
        if (iVar5 == -1) {
LAB_23aaf8f70:
          plStack_d0 = *(longlong **)(param_1 + 0x60);
          pcVar20 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          pcVar18 = *(code **)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
joined_r0x00023aaf89d2:
          if (pcVar20 != (code *)0x0) {
            plVar8 = *(longlong **)(pcVar20 + 0x18);
joined_r0x00023aaf8f52:
            if (plVar8 != plVar3) {
              plVar8 = (longlong *)0x0;
              uVar21 = 0x41;
              pcVar22 = _PyRuntime_exref;
              goto LAB_23aaf85e0;
            }
            goto LAB_23aaf8f60;
          }
        }
        else {
          if (iVar5 == 1) {
LAB_23aaf7eda:
            plVar8 = (longlong *)FUN_23e936ef0(param_1,plVar7);
            if (plVar8 == (longlong *)0x0) {
              plStack_d0 = *(longlong **)(param_1 + 0x60);
              pcVar20 = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              pcVar18 = *(code **)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              pcVar22 = _PyRuntime_exref;
              if (pcVar20 != (code *)0x0) {
                pcVar16 = pcVar20;
                pcVar19 = pcVar18;
                if (plVar3 == *(longlong **)(pcVar20 + 0x18)) goto LAB_23aaf8670;
                uVar21 = 0x42;
                goto LAB_23aaf85e0;
              }
              iVar5 = 0x42;
              goto LAB_23aaf88c8;
            }
            lVar9 = FUN_23ebc0cf0();
            if (lVar9 == 0) {
              FUN_23e915740(param_1,&plStack_78,DAT_23ed8fba8);
              plStack_d0._0_4_ = 0x45;
              pcVar22 = _PyRuntime_exref;
              pcVar20 = pcStack_68;
              plVar11 = plStack_78;
              pcVar18 = pcStack_70;
              goto LAB_23aaf8a40;
            }
            plVar10 = (longlong *)FUN_23e8bc2f0(lVar9,DAT_23ed8fbb0);
            plVar11 = _DAT_23ed8fbb8;
            if (plVar10 == (longlong *)0x0) {
              plVar11 = *(longlong **)(param_1 + 0x60);
              pcVar20 = *(code **)(param_1 + 0x70);
              plStack_d0._0_4_ = 0x45;
              *(undefined8 *)(param_1 + 0x70) = 0;
              pcVar22 = _PyRuntime_exref;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              pcVar18 = *(code **)(param_1 + 0x68);
              goto LAB_23aaf8a40;
            }
            lVar9 = *(longlong *)(param_1 + 0x10);
            plVar12 = *(longlong **)(lVar9 + 0xe20);
            if (plVar12 == (longlong *)0x0) {
              plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
            }
            else {
              lVar14 = plVar12[3];
              *(int *)(lVar9 + 0xebc) = *(int *)(lVar9 + 0xebc) + -1;
              *(longlong *)(lVar9 + 0xe20) = lVar14;
              *plVar12 = 1;
            }
            pcVar18 = _PyRuntime_exref;
            plVar12[4] = 0;
            lVar9 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar18 + 0x1f8) + 0x10) + 0x2e8);
            lVar14 = plVar12[-1];
            puVar2 = *(undefined8 **)(lVar9 + 8);
            *puVar2 = plVar12 + -2;
            plVar12[-2] = lVar9;
            plVar12[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar2;
            *(longlong **)(lVar9 + 8) = plVar12 + -2;
            *plVar11 = *plVar11 + 1;
            plVar12[3] = (longlong)plVar11;
            pcVar20 = DAT_23ed6cd28;
            pplVar23 = &DAT_23ed6a4c0;
            if (DAT_23ed6a4c0 == (longlong *)0x0) {
              plVar11 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
              if (plVar11 == (longlong *)0x0) goto LAB_23aaf9874;
              *plVar11 = *plVar11 + 1;
              DAT_23ed6a4c0 = plVar11;
            }
            pplVar23 = &plStack_78;
            pcStack_70 = pcVar20;
            plStack_78 = plVar8;
            lVar9 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,pplVar23);
            pcVar22 = pcVar18;
            if (lVar9 == 0) {
              plVar11 = *(longlong **)(param_1 + 0x60);
              pcVar18 = *(code **)(param_1 + 0x68);
              pcVar20 = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
              *plVar12 = *plVar12 + -1;
              plStack_d0._0_4_ = 0x45;
              if (*plVar12 == 0) {
                (**(code **)(plVar12[1] + 0x30))(plVar12);
                plStack_d0._0_4_ = 0x45;
              }
              goto LAB_23aaf8a40;
            }
            plVar12[4] = lVar9;
            plVar11 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar12);
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            if (plVar11 == (longlong *)0x0) {
              plVar11 = *(longlong **)(param_1 + 0x60);
              pcVar18 = *(code **)(param_1 + 0x68);
              pcVar20 = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plStack_d0._0_4_ = 0x45;
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
                plStack_d0._0_4_ = 0x45;
              }
              goto LAB_23aaf8a40;
            }
            *(undefined4 *)(plVar3 + 5) = 0x45;
            plVar12 = (longlong *)FUN_23e914090(param_1,plVar10,plVar11);
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            if (plVar12 == (longlong *)0x0) {
              plVar11 = *(longlong **)(param_1 + 0x60);
              pcVar20 = *(code **)(param_1 + 0x70);
              plStack_d0._0_4_ = 0x45;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              pcVar18 = *(code **)(param_1 + 0x68);
              goto LAB_23aaf8a40;
            }
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            lVar9 = *(longlong *)(DAT_23ed8fb58 + 0x20);
            if (*(char *)(lVar9 + 10) == '\0') {
              plVar11 = (longlong *)FUN_23a37a020(DAT_23ed8fb58,_DAT_23ed8fbc0);
              if (plVar11 == (longlong *)0x0) goto LAB_23aaf95f0;
              lVar14 = *plVar11;
LAB_23aaf95e7:
              if (lVar14 == 0) goto LAB_23aaf95f0;
            }
            else {
              iVar5 = *(int *)(lVar9 + 0xc);
              if (*(int *)(lVar9 + 0xc) == 0) {
                *(int *)(lVar9 + 0xc) = DAT_23ec107d0;
                iVar5 = DAT_23ec107d0;
                DAT_23ec107d0 = DAT_23ec107d0 + 1;
              }
              if (_DAT_23ec107d4 != iVar5) {
                _DAT_23ec107d4 = iVar5;
                _DAT_23ed90cf8 =
                     FUN_23e8cbd60(lVar9,_DAT_23ed8fbc0,*(undefined8 *)(_DAT_23ed8fbc0 + 0x18));
              }
              if (-1 < _DAT_23ed90cf8) {
                lVar1 = lVar9 + 0x20 + (1L << (*(byte *)(lVar9 + 9) & 0x3f));
                lVar14 = *(longlong *)(lVar1 + 8 + _DAT_23ed90cf8 * 0x10);
                if (lVar14 != 0) goto LAB_23aaf8140;
                _DAT_23ed90cf8 =
                     FUN_23e8cbd60(lVar9,_DAT_23ed8fbc0,*(undefined8 *)(_DAT_23ed8fbc0 + 0x18));
                if (-1 < _DAT_23ed90cf8) {
                  lVar14 = *(longlong *)(lVar1 + 8 + _DAT_23ed90cf8 * 0x10);
                  goto LAB_23aaf95e7;
                }
              }
LAB_23aaf95f0:
              plVar11 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23ed8fbc0);
              if ((plVar11 == (longlong *)0x0) || (lVar14 = *plVar11, lVar14 == 0)) {
                FUN_23e915740(param_1,pplVar23,_DAT_23ed8fbc0);
                plStack_d0._0_4_ = 0x48;
                pcVar20 = pcStack_68;
                plVar11 = plStack_78;
                pcVar18 = pcStack_70;
                goto LAB_23aaf8a40;
              }
            }
LAB_23aaf8140:
            plVar11 = (longlong *)FUN_23e8bc2f0(lVar14,_DAT_23ed8fbc8);
            if (plVar11 != (longlong *)0x0) {
              lVar9 = *(longlong *)(param_1 + 0x10);
              plVar10 = *(longlong **)(lVar9 + 0xe18);
              if (plVar10 == (longlong *)0x0) {
                plVar10 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,1);
              }
              else {
                lVar14 = plVar10[3];
                *(int *)(lVar9 + 0xeb8) = *(int *)(lVar9 + 0xeb8) + -1;
                *(longlong *)(lVar9 + 0xe18) = lVar14;
                *plVar10 = 1;
              }
              lVar9 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar18 + 0x1f8) + 0x10) + 0x2e8);
              lVar14 = plVar10[-1];
              puVar2 = *(undefined8 **)(lVar9 + 8);
              *puVar2 = plVar10 + -2;
              plVar10[-2] = lVar9;
              plVar10[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar2;
              *(longlong **)(lVar9 + 8) = plVar10 + -2;
              uVar4 = _DAT_23ed8fbd0;
              *plVar8 = *plVar8 + 1;
              plVar10[3] = (longlong)plVar8;
              plVar12 = (longlong *)FUN_23e8d7870(param_1,uVar4);
              *(undefined4 *)(plVar3 + 5) = 0x48;
              plVar13 = (longlong *)FUN_23a334c60(param_1,plVar11,plVar10,plVar12);
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                (**(code **)(plVar12[1] + 0x30))(plVar12);
              }
              if (plVar13 != (longlong *)0x0) {
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                lVar14 = FUN_23ebc0cf0();
                lVar9 = _DAT_23ed8fbd8;
                if (lVar14 == 0) goto LAB_23aaf9887;
                *(undefined4 *)(plVar3 + 5) = 0x4a;
                plVar11 = (longlong *)
                          FUN_23e915840(param_1,lVar14,DAT_23ed8fbb0,*(undefined8 *)(lVar9 + 0x18));
                if (plVar11 != (longlong *)0x0) {
                  *plVar11 = *plVar11 + -1;
                  pplVar23 = (longlong **)_Py_NoneStruct_exref;
                  if (*plVar11 == 0) {
                    FUN_23a334bc0(plVar11);
                  }
LAB_23aaf84ad:
                  lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                  plVar3 = *(longlong **)(lVar9 + 0x28);
                  plVar11 = (longlong *)plVar3[2];
                  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30)
                  ;
                  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
                  if (plVar11 != (longlong *)0x0) {
                    plVar3[2] = 0;
                    *plVar11 = *plVar11 + -1;
                    if (*plVar11 == 0) {
                      (**(code **)(plVar11[1] + 0x30))();
                    }
                  }
                  *plVar3 = *plVar3 + -1;
                  if (*plVar3 == 0) {
                    (**(code **)(plVar3[1] + 0x30))(plVar3);
                  }
                  *pplVar23 = (longlong *)((longlong)*pplVar23 + 1);
                  plVar3[0xf] = 0;
                  *(longlong *)pcVar6 = *(longlong *)pcVar6 + -1;
                  if (*(longlong *)pcVar6 == 0) {
                    (**(code **)(*(longlong *)(pcVar6 + 8) + 0x30))(pcVar6);
                  }
                  *plVar7 = *plVar7 + -1;
                  if (*plVar7 == 0) {
                    (**(code **)(plVar7[1] + 0x30))(plVar7);
                  }
                  if (plVar8 != (longlong *)0x0) {
                    *plVar8 = *plVar8 + -1;
                    if (*plVar8 == 0) {
                      (**(code **)(plVar8[1] + 0x30))(plVar8);
                      return (code *)pplVar23;
                    }
                    return (code *)pplVar23;
                  }
                  return (code *)pplVar23;
                }
                plVar11 = *(longlong **)(param_1 + 0x60);
                pcVar20 = *(code **)(param_1 + 0x70);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plStack_d0._0_4_ = 0x4a;
                *(undefined8 *)(param_1 + 0x70) = 0;
                pcVar18 = *(code **)(param_1 + 0x68);
                goto LAB_23aaf8a40;
              }
            }
            plVar11 = *(longlong **)(param_1 + 0x60);
            pcVar20 = *(code **)(param_1 + 0x70);
            plStack_d0._0_4_ = 0x48;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            pcVar18 = *(code **)(param_1 + 0x68);
LAB_23aaf8a40:
            do {
              plVar10 = *(longlong **)(param_1 + 0x138);
              auStack_98._8_8_ = pcVar18;
              auStack_98._0_8_ = plVar11;
              if (plVar10 != (longlong *)0x0) {
                *plVar10 = *plVar10 + 1;
              }
              pcVar18 = DAT_23ed6a4f8;
              apcStack_88[0] = pcVar20;
              if (pcVar20 == (code *)0x0) {
                if (DAT_23ed6a4f8 == (code *)0x0) {
                  pcVar18 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
                }
                else {
                  pcVar20 = *(code **)DAT_23ed6a4f8;
                  *(longlong *)DAT_23ed6a4f8 = 1;
                  DAT_23ed6a4f8 = pcVar20;
                  DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                }
                *(longlong *)(pcVar18 + 0x10) = 0;
                *(longlong **)(pcVar18 + 0x18) = plVar3;
                *plVar3 = *plVar3 + 1;
                lVar9 = *(longlong *)(pcVar22 + 0x1f8);
                *(undefined4 *)(pcVar18 + 0x24) = plStack_d0._0_4_;
                lVar9 = *(longlong *)(lVar9 + 0x10);
                *(undefined4 *)(pcVar18 + 0x20) = 0xffffffff;
                lVar9 = *(longlong *)(lVar9 + 0x2e8);
                lVar14 = *(longlong *)(pcVar18 + -8);
                puVar2 = *(undefined8 **)(lVar9 + 8);
                *puVar2 = pcVar18 + -0x10;
                *(longlong *)(pcVar18 + -0x10) = lVar9;
                *(ulonglong *)(pcVar18 + -8) = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar2;
                *(code **)(lVar9 + 8) = pcVar18 + -0x10;
                if ((apcStack_88[0] != (code *)0x0) &&
                   (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
                   *(longlong *)apcStack_88[0] == 0)) {
                  (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))(apcStack_88[0]);
                }
              }
              else {
                if (DAT_23ed6a4f8 == (code *)0x0) {
                  pcVar18 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
                }
                else {
                  pcVar19 = *(code **)DAT_23ed6a4f8;
                  *(longlong *)DAT_23ed6a4f8 = 1;
                  DAT_23ed6a4f8 = pcVar19;
                  DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                }
                *(longlong **)(pcVar18 + 0x18) = plVar3;
                *plVar3 = *plVar3 + 1;
                lVar9 = *(longlong *)(pcVar22 + 0x1f8);
                *(undefined4 *)(pcVar18 + 0x24) = plStack_d0._0_4_;
                lVar9 = *(longlong *)(lVar9 + 0x10);
                *(undefined4 *)(pcVar18 + 0x20) = 0xffffffff;
                lVar9 = *(longlong *)(lVar9 + 0x2e8);
                lVar14 = *(longlong *)(pcVar18 + -8);
                puVar2 = *(undefined8 **)(lVar9 + 8);
                *puVar2 = pcVar18 + -0x10;
                *(longlong *)(pcVar18 + -0x10) = lVar9;
                *(ulonglong *)(pcVar18 + -8) = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar2;
                *(code **)(lVar9 + 8) = pcVar18 + -0x10;
                *(code **)(pcVar18 + 0x10) = pcVar20;
                *(longlong *)pcVar20 = *(longlong *)pcVar20 + 1;
                if ((apcStack_88[0] != (code *)0x0) &&
                   (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
                   *(longlong *)apcStack_88[0] == 0)) {
                  (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))();
                }
              }
              pplVar23 = (longlong **)_Py_NoneStruct_exref;
              apcStack_88[0] = pcVar18;
              if (((code *)auStack_98._0_8_ != _Py_NoneStruct_exref) &&
                 ((code *)auStack_98._0_8_ != (code *)0x0)) {
                FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,apcStack_88);
              }
              plVar11 = *(longlong **)(auStack_98._8_8_ + 0x28);
              if ((longlong **)apcStack_88[0] == pplVar23) {
                pcVar20 = (code *)0x0;
              }
              else {
                pcVar20 = apcStack_88[0];
                if (apcStack_88[0] != (code *)0x0) {
                  *(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + 1;
                }
              }
              *(code **)(auStack_98._8_8_ + 0x28) = pcVar20;
              if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
                (**(code **)(plVar11[1] + 0x30))();
              }
              plVar11 = *(longlong **)(param_1 + 0x138);
              *(undefined8 *)(param_1 + 0x138) = auStack_98._8_8_;
              if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
                (**(code **)(plVar11[1] + 0x30))();
              }
              *(longlong *)auStack_98._0_8_ = *(longlong *)auStack_98._0_8_ + -1;
              if (*(longlong *)auStack_98._0_8_ == 0) {
                (**(code **)(*(longlong *)(auStack_98._0_8_ + 8) + 0x30))();
              }
              if ((apcStack_88[0] != (code *)0x0) &&
                 (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
                 *(longlong *)apcStack_88[0] == 0)) {
                (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))();
              }
              apcStack_88[0] = (code *)0x0;
              auStack_98 = (undefined1  [16])0x0;
              iVar5 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                                    *(undefined8 *)PyExc_Exception_exref);
              if (iVar5 == 0) {
                pcVar19 = *(code **)(param_1 + 0x138);
                if (((longlong **)pcVar19 == pplVar23) || (pcVar19 == (code *)0x0)) {
                  plStack_d0 = *(longlong **)PyExc_RuntimeError_exref;
                  pcVar18 = (code *)PyUnicode_FromString("No active exception to reraise");
                  *plStack_d0 = *plStack_d0 + 1;
                  iVar5 = 0x44;
                  pcVar19 = *(code **)(param_1 + 0x138);
                  *(longlong **)(param_1 + 0x138) = plVar10;
                  if ((pcVar19 == (code *)0x0) ||
                     (*(longlong *)pcVar19 = *(longlong *)pcVar19 + -1, *(longlong *)pcVar19 != 0))
                  goto LAB_23aaf88c8;
LAB_23aaf96b2:
                  (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))();
                  if (iVar5 != 0) goto LAB_23aaf88c8;
                }
                else {
                  plStack_d0 = *(longlong **)(pcVar19 + 8);
                  pcVar20 = *(code **)(pcVar19 + 0x28);
                  *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
                  *plStack_d0 = *plStack_d0 + 1;
                  pcVar18 = pcVar19;
                  if (pcVar20 != (code *)0x0) {
                    *(longlong *)pcVar20 = *(longlong *)pcVar20 + 1;
                    if (*(longlong **)(pcVar20 + 0x18) == plVar3) {
                      *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(pcVar20 + 0x24);
                    }
                    *(longlong **)(param_1 + 0x138) = plVar10;
                    *(longlong *)pcVar19 = *(longlong *)pcVar19 + -1;
                    if (*(longlong *)pcVar19 == 0) {
                      (*(code *)plStack_d0[6])(pcVar19);
                      iVar5 = 0;
                      goto LAB_23aaf926a;
                    }
                    pcVar16 = pcVar20;
                    if (plVar3 != *(longlong **)(pcVar20 + 0x18)) goto LAB_23aaf927d;
                    goto LAB_23aaf8670;
                  }
                  *(longlong **)(param_1 + 0x138) = plVar10;
                  *(longlong *)pcVar19 = *(longlong *)pcVar19 + -1;
                  if (*(longlong *)pcVar19 == 0) {
                    iVar5 = 0;
                    goto LAB_23aaf96b2;
                  }
                }
                iVar5 = (int)plVar3[5];
                goto LAB_23aaf88c8;
              }
              plVar11 = *(longlong **)(param_1 + 0x138);
              *plVar11 = *plVar11 + 1;
              lVar9 = FUN_23ebc0cf0();
              if (lVar9 == 0) {
                FUN_23e915740(param_1,&plStack_78,DAT_23ed8fba8);
                plStack_d0 = plStack_78;
                pcVar20 = pcStack_68;
                pcVar18 = pcStack_70;
                goto LAB_23aaf93a0;
              }
              plVar13 = (longlong *)FUN_23e8bc2f0(lVar9,DAT_23ed8fbe0);
              plVar12 = _DAT_23ed8fbe8;
              if (plVar13 == (longlong *)0x0) {
                plStack_d0 = *(longlong **)(param_1 + 0x60);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                pcVar20 = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                pcVar18 = *(code **)(param_1 + 0x68);
                goto LAB_23aaf93a0;
              }
              lVar9 = *(longlong *)(param_1 + 0x10);
              plVar15 = *(longlong **)(lVar9 + 0xe20);
              if (plVar15 == (longlong *)0x0) {
                plVar15 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
              }
              else {
                lVar14 = plVar15[3];
                *(int *)(lVar9 + 0xebc) = *(int *)(lVar9 + 0xebc) + -1;
                *(longlong *)(lVar9 + 0xe20) = lVar14;
                *plVar15 = 1;
              }
              lVar9 = *(longlong *)(pcVar22 + 0x1f8);
              plVar15[4] = 0;
              lVar9 = *(longlong *)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
              lVar14 = plVar15[-1];
              puVar2 = *(undefined8 **)(lVar9 + 8);
              *puVar2 = plVar15 + -2;
              plVar15[-2] = lVar9;
              plVar15[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar2;
              *(longlong **)(lVar9 + 8) = plVar15 + -2;
              plVar17 = DAT_23ed6a4c0;
              *plVar12 = *plVar12 + 1;
              plVar15[3] = (longlong)plVar12;
              pcVar20 = DAT_23ed6cd28;
              if (plVar17 != (longlong *)0x0) goto LAB_23aaf8d36;
              pcVar18 = pcVar22;
              plVar17 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
              if (plVar17 != (longlong *)0x0) goto code_r0x00023aaf955a;
LAB_23aaf9874:
              PyErr_PrintEx(0);
              Py_Exit(1);
LAB_23aaf9887:
              FUN_23e915740(param_1,pplVar23,DAT_23ed8fba8);
              plStack_d0._0_4_ = 0x4a;
              pcVar22 = pcVar18;
              pcVar20 = pcStack_68;
              plVar11 = plStack_78;
              pcVar18 = pcStack_70;
            } while( true );
          }
          plVar8 = (longlong *)FUN_23e936ef0(param_1,plVar7);
          if (plVar8 == (longlong *)0x0) {
LAB_23aaf8fb8:
            plVar8 = (longlong *)0x0;
            plStack_d0 = *(longlong **)(param_1 + 0x60);
            pcVar20 = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            pcVar18 = *(code **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (pcVar20 != (code *)0x0) {
              pcVar16 = pcVar20;
              pcVar19 = pcVar18;
              if (plVar3 == *(longlong **)(pcVar20 + 0x18)) goto LAB_23aaf8670;
              uVar21 = 0x41;
              pcVar22 = _PyRuntime_exref;
              goto LAB_23aaf85e0;
            }
          }
          else {
            plVar11 = (longlong *)FUN_23e936d70(param_1,plVar8);
            *plVar8 = *plVar8 + -1;
            if (*plVar8 == 0) {
              (**(code **)(plVar8[1] + 0x30))(plVar8);
            }
            if (plVar11 == (longlong *)0x0) {
              plStack_d0 = *(longlong **)(param_1 + 0x60);
              pcVar20 = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              pcVar18 = *(code **)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            }
            else {
              plVar8 = (longlong *)FUN_23e8bc2f0(plVar11,_DAT_23ed8fb98);
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
              if (plVar8 == (longlong *)0x0) goto LAB_23aaf8fb8;
              *(undefined4 *)(plVar3 + 5) = 0x41;
              plVar11 = (longlong *)FUN_23e94bb80(param_1,plVar8,_DAT_23ed8fba0);
              *plVar8 = *plVar8 + -1;
              if (*plVar8 == 0) {
                (**(code **)(plVar8[1] + 0x30))(plVar8);
              }
              if (plVar11 == (longlong *)0x0) goto LAB_23aaf8f70;
              iVar5 = FUN_23a35f020(plVar11);
              lVar9 = *plVar11 + -1;
              if (iVar5 != -1) {
                *plVar11 = lVar9;
                if (lVar9 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                if (iVar5 != 1) {
                  plVar8 = (longlong *)0x0;
                  pplVar23 = (longlong **)_Py_NoneStruct_exref;
                  goto LAB_23aaf84ad;
                }
                goto LAB_23aaf7eda;
              }
              plStack_d0 = *(longlong **)(param_1 + 0x60);
              pcVar18 = *(code **)(param_1 + 0x68);
              pcVar20 = *(code **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *plVar11 = lVar9;
              if (lVar9 == 0) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
                goto joined_r0x00023aaf89d2;
              }
            }
            if (pcVar20 != (code *)0x0) {
              plVar8 = *(longlong **)(pcVar20 + 0x18);
              goto joined_r0x00023aaf8f52;
            }
          }
        }
        plVar8 = (longlong *)0x0;
        iVar5 = 0x41;
        pcVar22 = _PyRuntime_exref;
      }
    }
  }
LAB_23aaf88c8:
  pcVar16 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar16 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    pcVar20 = *(code **)DAT_23ed6a4f8;
    *(longlong *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar20;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  *(longlong *)(pcVar16 + 0x10) = 0;
  *(longlong **)(pcVar16 + 0x18) = plVar3;
  *plVar3 = *plVar3 + 1;
  lVar9 = *(longlong *)(pcVar22 + 0x1f8);
  *(int *)(pcVar16 + 0x24) = iVar5;
  lVar9 = *(longlong *)(lVar9 + 0x10);
  *(undefined4 *)(pcVar16 + 0x20) = 0xffffffff;
  lVar9 = *(longlong *)(lVar9 + 0x2e8);
  lVar14 = *(longlong *)(pcVar16 + -8);
  puVar2 = *(undefined8 **)(lVar9 + 8);
  *puVar2 = pcVar16 + -0x10;
  *(longlong *)(pcVar16 + -0x10) = lVar9;
  *(ulonglong *)(pcVar16 + -8) = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar2;
  *(code **)(lVar9 + 8) = pcVar16 + -0x10;
  pcVar19 = pcVar18;
LAB_23aaf8670:
  FUN_23e8bba40(plVar3,&DAT_23ec31985,pcVar6,plVar7,plVar8,0);
  if (DAT_23ed90d08 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    DAT_23ed90d08 = (longlong *)0x0;
  }
  lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar9 + 0x28);
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
  plVar11 = (longlong *)plVar3[2];
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar11 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  plVar3[0xf] = 0;
  if ((pcVar6 != (code *)0x0) &&
     (*(longlong *)pcVar6 = *(longlong *)pcVar6 + -1, *(longlong *)pcVar6 == 0)) {
    (**(code **)(*(longlong *)(pcVar6 + 8) + 0x30))(pcVar6);
  }
  if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  FUN_23a33aa70(param_1,plStack_d0,pcVar19,pcVar16);
  return (code *)0x0;
code_r0x00023aaf955a:
  *plVar17 = *plVar17 + 1;
  DAT_23ed6a4c0 = plVar17;
LAB_23aaf8d36:
  pcStack_a0 = pcVar20;
  plStack_a8 = plVar11;
  lVar9 = FUN_23e94ed00(param_1,plVar17,&plStack_a8);
  if (lVar9 == 0) {
    plStack_d0 = *(longlong **)(param_1 + 0x60);
    pcVar18 = *(code **)(param_1 + 0x68);
    pcVar20 = *(code **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    lVar9 = *plVar13;
    *plVar13 = lVar9 + -1;
    if (lVar9 + -1 == 0) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    *plVar15 = *plVar15 + -1;
    if (*plVar15 == 0) {
      (**(code **)(plVar15[1] + 0x30))(plVar15);
    }
  }
  else {
    plVar15[4] = lVar9;
    plVar12 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar15);
    *plVar15 = *plVar15 + -1;
    if (*plVar15 == 0) {
      (**(code **)(plVar15[1] + 0x30))(plVar15);
    }
    if (plVar12 == (longlong *)0x0) {
      plStack_d0 = *(longlong **)(param_1 + 0x60);
      pcVar18 = *(code **)(param_1 + 0x68);
      pcVar20 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      lVar9 = *plVar13;
      *plVar13 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        FUN_23a334bc0(plVar13);
      }
    }
    else {
      *(undefined4 *)(plVar3 + 5) = 0x4c;
      plVar15 = (longlong *)FUN_23e914090(param_1,plVar13,plVar12);
      lVar9 = *plVar13;
      *plVar13 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar13[1] + 0x30))();
      }
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      if (plVar15 != (longlong *)0x0) {
        *plVar15 = *plVar15 + -1;
        if (*plVar15 == 0) {
          (**(code **)(plVar15[1] + 0x30))(plVar15);
        }
        lVar9 = *plVar11;
        *plVar11 = lVar9 + -1;
        if (lVar9 + -1 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        plVar3 = *(longlong **)(param_1 + 0x138);
        *(longlong **)(param_1 + 0x138) = plVar10;
        if ((plVar3 != (longlong *)0x0) && (*plVar3 = *plVar3 + -1, *plVar3 == 0)) {
          (**(code **)(plVar3[1] + 0x30))();
        }
        goto LAB_23aaf84ad;
      }
      plStack_d0 = *(longlong **)(param_1 + 0x60);
      pcVar20 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcVar18 = *(code **)(param_1 + 0x68);
    }
  }
LAB_23aaf93a0:
  lVar9 = *plVar11;
  *plVar11 = lVar9 + -1;
  if (lVar9 + -1 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  plVar11 = *(longlong **)(param_1 + 0x138);
  *(longlong **)(param_1 + 0x138) = plVar10;
  if (plVar11 == (longlong *)0x0) {
    if (pcVar20 != (code *)0x0) {
      plVar11 = *(longlong **)(pcVar20 + 0x18);
joined_r0x00023aaf9435:
      pcVar16 = pcVar20;
      pcVar19 = pcVar18;
      if (plVar3 == plVar11) goto LAB_23aaf8670;
      uVar21 = 0x4c;
      goto LAB_23aaf85e0;
    }
  }
  else {
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))();
      if (pcVar20 != (code *)0x0) {
        iVar5 = 0x4c;
LAB_23aaf926a:
        pcVar16 = pcVar20;
        pcVar19 = pcVar18;
        if (*(longlong **)(pcVar20 + 0x18) == plVar3) goto LAB_23aaf8670;
        if (iVar5 == 0) {
LAB_23aaf927d:
          uVar21 = (undefined4)plVar3[5];
        }
        else {
          uVar21 = 0x4c;
        }
        goto LAB_23aaf85e0;
      }
    }
    else if (pcVar20 != (code *)0x0) {
      plVar11 = *(longlong **)(pcVar20 + 0x18);
      goto joined_r0x00023aaf9435;
    }
  }
  iVar5 = 0x4c;
  goto LAB_23aaf88c8;
}
