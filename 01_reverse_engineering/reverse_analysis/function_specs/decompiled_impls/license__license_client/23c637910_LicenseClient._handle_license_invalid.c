/* ===== 23c637910 license.license_client:400 ===== */
/* ghidra_name=FUN_23c637910 entry=23c637910 size=12565 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23c637910(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  code *pcVar4;
  bool bVar5;
  code *pcVar6;
  char cVar7;
  int iVar8;
  longlong lVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  code *pcVar13;
  longlong *plVar14;
  longlong lVar15;
  undefined8 uVar16;
  longlong *plVar17;
  code *pcVar18;
  code *pcVar19;
  code *pcVar20;
  undefined4 uVar21;
  undefined1 auVar22 [8];
  code *pcVar23;
  code *pcStack_130;
  code *pcStack_128;
  longlong *plStack_120;
  code *pcStack_118;
  undefined1 auStack_f8 [16];
  code *apcStack_e8 [2];
  code *pcStack_d8;
  code *pcStack_d0;
  code *pcStack_c8;
  undefined1 auStack_b8 [16];
  code *apcStack_a8 [2];
  undefined1 auStack_98 [8];
  code *pcStack_90;
  code *apcStack_88 [2];
  code *pcStack_78;
  code *pcStack_70;
  code *pcStack_68;
  
  plVar10 = _DAT_23ee29c40;
  plVar1 = (longlong *)*param_3;
  apcStack_88[0] = (code *)0x0;
  auStack_98 = (undefined1  [8])0x0;
  pcStack_90 = (code *)0x0;
  if (_DAT_23ee29c40 == (longlong *)0x0) {
LAB_23c63796d:
    _DAT_23ee29c40 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23ee29c38,DAT_23ee29d18,0x20);
  }
  else {
    lVar15 = *_DAT_23ee29c40;
    if (1 < lVar15) {
      *_DAT_23ee29c40 = lVar15 + -1;
      goto LAB_23c63796d;
    }
    if (_DAT_23ee29c40[2] != 0) {
      *_DAT_23ee29c40 = lVar15 + -1;
      if (lVar15 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23c63796d;
    }
  }
  plVar3 = _DAT_23ee29c40;
  lVar15 = *(longlong *)(param_1 + 0x38);
  plVar10 = _DAT_23ee29c40 + 9;
  lVar9 = *(longlong *)(lVar15 + 8);
  _DAT_23ee29c40[0xf] = lVar9;
  *(longlong **)(lVar15 + 8) = plVar10;
  if ((lVar9 != 0) &&
     (((*(char *)(lVar9 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar9 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar9 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar9 + 0x38))
       ) && (plVar3[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar9 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  *(undefined4 *)(plVar3 + 8) = 0;
  lVar9 = FUN_23ead5f40();
  lVar15 = _DAT_23ee28950;
  if (lVar9 == 0) {
    FUN_23e915740(param_1,auStack_98,DAT_23ee283f8);
    if (apcStack_88[0] == (code *)0x0) {
LAB_23c63a193:
      plStack_120 = (longlong *)0x0;
      iVar8 = 0x192;
      pcStack_128 = (code *)0x0;
      pcStack_130 = _PyRuntime_exref;
      goto LAB_23c639445;
    }
    plVar10 = *(longlong **)(apcStack_88[0] + 0x18);
joined_r0x00023c63962c:
    plStack_120 = (longlong *)0x0;
    if (plVar10 == plVar3) {
LAB_23c639688:
      pcStack_128 = (code *)0x0;
      plStack_120 = (longlong *)0x0;
      pcVar18 = apcStack_88[0];
      goto LAB_23c6386f0;
    }
    iVar8 = 0x192;
    pcStack_128 = (code *)0x0;
    pcStack_130 = _PyRuntime_exref;
LAB_23c638c43:
    pcVar20 = apcStack_88[0];
    pcVar18 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar18 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar23 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar23;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    *(longlong **)(pcVar18 + 0x18) = plVar3;
    *plVar3 = *plVar3 + 1;
    lVar15 = *(longlong *)(pcStack_130 + 0x1f8);
    *(int *)(pcVar18 + 0x24) = iVar8;
    *(undefined4 *)(pcVar18 + 0x20) = 0xffffffff;
    lVar15 = *(longlong *)(*(longlong *)(lVar15 + 0x10) + 0x2e8);
    lVar9 = *(longlong *)(pcVar18 + -8);
    puVar2 = *(undefined8 **)(lVar15 + 8);
    *puVar2 = pcVar18 + -0x10;
    *(longlong *)(pcVar18 + -0x10) = lVar15;
    *(ulonglong *)(pcVar18 + -8) = (ulonglong)((uint)lVar9 & 3) | (ulonglong)puVar2;
    *(code **)(lVar15 + 8) = pcVar18 + -0x10;
    *(code **)(pcVar18 + 0x10) = pcVar20;
    *(longlong *)pcVar20 = *(longlong *)pcVar20 + 1;
    pcVar20 = apcStack_88[0];
  }
  else {
    *(undefined4 *)(plVar3 + 5) = 0x192;
    plVar10 = (longlong *)FUN_23e915840(param_1,lVar9,DAT_23ee28400,*(undefined8 *)(lVar15 + 0x18));
    if (plVar10 == (longlong *)0x0) {
      auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_90 = *(code **)(param_1 + 0x68);
      apcStack_88[0] = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (apcStack_88[0] == (code *)0x0) goto LAB_23c63a193;
      plVar10 = *(longlong **)(apcStack_88[0] + 0x18);
      goto joined_r0x00023c63962c;
    }
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    pcStack_128 = (code *)0x0;
    if (plVar1 != (longlong *)0x0) {
      plStack_120 = (longlong *)0x0;
LAB_23c637a54:
      do {
        plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23ee283d0);
        if (plVar10 == (longlong *)0x0) {
LAB_23c6396a0:
          auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_90 = *(code **)(param_1 + 0x68);
          apcStack_88[0] = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (apcStack_88[0] == (code *)0x0) goto LAB_23c639e72;
          pcVar18 = apcStack_88[0];
          if (plVar3 == *(longlong **)(apcStack_88[0] + 0x18)) goto LAB_23c6386f0;
          goto LAB_23c6396e1;
        }
        *(undefined4 *)(plVar3 + 5) = 0x194;
        plVar11 = (longlong *)FUN_23e91bfe0(param_1,plVar10,_DAT_23ee28960);
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if (plVar11 == (longlong *)0x0) goto LAB_23c6396a0;
        iVar8 = FUN_23a35f020(plVar11);
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        if (iVar8 == -1) {
          auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_90 = *(code **)(param_1 + 0x68);
          apcStack_88[0] = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (apcStack_88[0] == (code *)0x0) goto LAB_23c639e72;
          pcVar18 = apcStack_88[0];
          if (*(longlong **)(apcStack_88[0] + 0x18) != plVar3) goto LAB_23c6396e1;
          goto LAB_23c6386f0;
        }
        pcVar18 = _Py_FalseStruct_exref;
        if (iVar8 == 0) {
          pcVar18 = _Py_TrueStruct_exref;
        }
        iVar8 = FUN_23a35f020(pcVar18);
        if (iVar8 == 0) {
LAB_23c639af9:
          lVar9 = FUN_23ead5f40();
          lVar15 = _DAT_23ee289a8;
          if (lVar9 == 0) {
            FUN_23e915740(param_1,auStack_98,DAT_23ee283f8);
          }
          else {
            *(undefined4 *)(plVar3 + 5) = 0x1ae;
            plVar10 = (longlong *)
                      FUN_23e915840(param_1,lVar9,DAT_23ee28400,*(undefined8 *)(lVar15 + 0x18));
            if (plVar10 != (longlong *)0x0) {
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
              lVar15 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
              plVar10 = *(longlong **)(lVar15 + 0x28);
              plVar3 = (longlong *)plVar10[2];
              *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar15 + 0x30);
              *(undefined4 *)(plVar10 + 8) = 0xffffffff;
              if (plVar3 != (longlong *)0x0) {
                plVar10[2] = 0;
                *plVar3 = *plVar3 + -1;
                if (*plVar3 == 0) {
                  (**(code **)(plVar3[1] + 0x30))();
                }
              }
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
              pcVar18 = _Py_NoneStruct_exref;
              plVar10[0xf] = 0;
              *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
              if ((plStack_120 != (longlong *)0x0) &&
                 (*plStack_120 = *plStack_120 + -1, *plStack_120 == 0)) {
                (**(code **)(plStack_120[1] + 0x30))(plStack_120);
              }
              if ((pcStack_128 != (code *)0x0) &&
                 (lVar15 = *(longlong *)pcStack_128, *(longlong *)pcStack_128 = lVar15 + -1,
                 lVar15 + -1 == 0)) {
                (**(code **)(*(longlong *)(pcStack_128 + 8) + 0x30))(pcStack_128);
              }
              *plVar1 = *plVar1 + -1;
              if (*plVar1 != 0) {
                return pcVar18;
              }
              (**(code **)(plVar1[1] + 0x30))(plVar1);
              return pcVar18;
            }
            auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_90 = *(code **)(param_1 + 0x68);
            apcStack_88[0] = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          }
          pcStack_130 = _PyRuntime_exref;
          if (apcStack_88[0] == (code *)0x0) {
            iVar8 = 0x1ae;
            goto LAB_23c639445;
          }
          pcVar18 = apcStack_88[0];
          if (*(longlong **)(apcStack_88[0] + 0x18) == plVar3) goto LAB_23c6386f0;
          iVar8 = 0x1ae;
          goto LAB_23c638c43;
        }
        lVar9 = FUN_23ead5f40();
        lVar15 = _DAT_23ee28968;
        if (lVar9 == 0) {
          FUN_23e915740(param_1,auStack_98,DAT_23ee283f8);
LAB_23c638ae9:
          iVar8 = 0x196;
          pcVar23 = _Py_NoneStruct_exref;
          pcVar18 = apcStack_88[0];
          auVar22 = auStack_98;
          pcVar20 = pcStack_90;
          goto LAB_23c638030;
        }
        *(undefined4 *)(plVar3 + 5) = 0x196;
        plVar10 = (longlong *)
                  FUN_23e915840(param_1,lVar9,DAT_23ee28400,*(undefined8 *)(lVar15 + 0x18));
        if (plVar10 == (longlong *)0x0) {
          apcStack_88[0] = *(code **)(param_1 + 0x70);
          auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_90 = *(code **)(param_1 + 0x68);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23c638ae9;
        }
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))();
        }
        plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23ee283e0);
        if (plVar10 == (longlong *)0x0) {
          auVar22 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcVar18 = *(code **)(param_1 + 0x70);
          iVar8 = 0x197;
          *(undefined8 *)(param_1 + 0x70) = 0;
          pcVar23 = _Py_NoneStruct_exref;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          pcVar20 = *(code **)(param_1 + 0x68);
          goto LAB_23c638030;
        }
        plVar11 = (longlong *)FUN_23e8d9880(plVar10,DAT_23ed6cd90);
        if (plVar11 == (longlong *)0x0) {
LAB_23c637fd8:
          pcVar18 = *(code **)(param_1 + 0x70);
          auVar22 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcVar20 = *(code **)(param_1 + 0x68);
          *(undefined8 *)(param_1 + 0x70) = 0;
          apcStack_88[0] = (code *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          auStack_98 = (undefined1  [8])0x0;
          pcStack_90 = (code *)0x0;
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))();
          }
LAB_23c638010:
          iVar8 = 0x197;
          pcVar23 = _Py_NoneStruct_exref;
          goto LAB_23c638030;
        }
        *(undefined4 *)(plVar3 + 5) = 0x197;
        plVar12 = (longlong *)FUN_23e91a870(param_1,plVar11);
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))();
        }
        if (plVar12 == (longlong *)0x0) goto LAB_23c637fd8;
        pcVar13 = (code *)FUN_23e8d9880(plVar10,DAT_23ed6cd98);
        if (pcVar13 == (code *)0x0) {
          pcVar18 = *(code **)(param_1 + 0x70);
          auVar22 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcVar20 = *(code **)(param_1 + 0x68);
          *(undefined8 *)(param_1 + 0x70) = 0;
          apcStack_88[0] = (code *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          auStack_98 = (undefined1  [8])0x0;
          pcStack_90 = (code *)0x0;
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            iVar8 = 0x197;
            pcVar23 = _Py_NoneStruct_exref;
            goto LAB_23c6393ed;
          }
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) {
            (**(code **)(plVar12[1] + 0x30))();
            iVar8 = 0x197;
            pcVar23 = _Py_NoneStruct_exref;
            goto LAB_23c638030;
          }
          goto LAB_23c638010;
        }
        *(undefined4 *)(plVar3 + 5) = 0x198;
        plVar11 = (longlong *)FUN_23e91bfe0(param_1,plVar1,_DAT_23ee28970);
        if (plVar11 == (longlong *)0x0) {
LAB_23c638e40:
          pcVar18 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          auVar22 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcVar20 = *(code **)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23c638e59:
          uVar21 = 0x198;
          pcStack_130 = _PyRuntime_exref;
          apcStack_88[0] = pcVar18;
          auStack_98 = auVar22;
          pcStack_90 = pcVar20;
LAB_23c638e7b:
          pcVar18 = apcStack_88[0];
          auStack_b8._8_8_ = pcStack_90;
          auStack_b8._0_8_ = auStack_98;
          apcStack_88[0] = (code *)0x0;
          plVar11 = *(longlong **)(param_1 + 0x138);
          auStack_98 = (undefined1  [8])0x0;
          pcStack_90 = (code *)0x0;
          apcStack_a8[0] = pcVar18;
          if (plVar11 != (longlong *)0x0) {
            *plVar11 = *plVar11 + 1;
          }
          pcVar20 = DAT_23ed6a4f8;
          if (pcVar18 == (code *)0x0) {
            if (DAT_23ed6a4f8 == (code *)0x0) {
              pcVar20 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
            }
            else {
              pcVar18 = *(code **)DAT_23ed6a4f8;
              *(longlong *)DAT_23ed6a4f8 = 1;
              DAT_23ed6a4f8 = pcVar18;
              DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
            }
            *(longlong *)(pcVar20 + 0x10) = 0;
            *(longlong **)(pcVar20 + 0x18) = plVar3;
            *plVar3 = *plVar3 + 1;
            lVar15 = *(longlong *)(pcStack_130 + 0x1f8);
            *(undefined4 *)(pcVar20 + 0x24) = uVar21;
            lVar15 = *(longlong *)(lVar15 + 0x10);
            *(undefined4 *)(pcVar20 + 0x20) = 0xffffffff;
            lVar15 = *(longlong *)(lVar15 + 0x2e8);
            lVar9 = *(longlong *)(pcVar20 + -8);
            puVar2 = *(undefined8 **)(lVar15 + 8);
            *puVar2 = pcVar20 + -0x10;
            *(longlong *)(pcVar20 + -0x10) = lVar15;
            *(ulonglong *)(pcVar20 + -8) = (ulonglong)((uint)lVar9 & 3) | (ulonglong)puVar2;
            *(code **)(lVar15 + 8) = pcVar20 + -0x10;
            if ((apcStack_a8[0] != (code *)0x0) &&
               (*(longlong *)apcStack_a8[0] = *(longlong *)apcStack_a8[0] + -1,
               *(longlong *)apcStack_a8[0] == 0)) {
              (**(code **)(*(longlong *)(apcStack_a8[0] + 8) + 0x30))(apcStack_a8[0]);
            }
          }
          else {
            if (DAT_23ed6a4f8 == (code *)0x0) {
              pcVar20 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
            }
            else {
              pcVar23 = *(code **)DAT_23ed6a4f8;
              *(longlong *)DAT_23ed6a4f8 = 1;
              DAT_23ed6a4f8 = pcVar23;
              DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
            }
            *(longlong **)(pcVar20 + 0x18) = plVar3;
            *plVar3 = *plVar3 + 1;
            lVar15 = *(longlong *)(pcStack_130 + 0x1f8);
            *(undefined4 *)(pcVar20 + 0x24) = uVar21;
            *(undefined4 *)(pcVar20 + 0x20) = 0xffffffff;
            lVar15 = *(longlong *)(*(longlong *)(lVar15 + 0x10) + 0x2e8);
            lVar9 = *(longlong *)(pcVar20 + -8);
            puVar2 = *(undefined8 **)(lVar15 + 8);
            *puVar2 = pcVar20 + -0x10;
            *(longlong *)(pcVar20 + -0x10) = lVar15;
            *(ulonglong *)(pcVar20 + -8) = (ulonglong)((uint)lVar9 & 3) | (ulonglong)puVar2;
            *(code **)(lVar15 + 8) = pcVar20 + -0x10;
            *(code **)(pcVar20 + 0x10) = pcVar18;
            *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
            if ((apcStack_a8[0] != (code *)0x0) &&
               (*(longlong *)apcStack_a8[0] = *(longlong *)apcStack_a8[0] + -1,
               *(longlong *)apcStack_a8[0] == 0)) {
              (**(code **)(*(longlong *)(apcStack_a8[0] + 8) + 0x30))();
            }
          }
          pcVar23 = _Py_NoneStruct_exref;
          apcStack_a8[0] = pcVar20;
          if (((code *)auStack_b8._0_8_ != _Py_NoneStruct_exref) &&
             ((code *)auStack_b8._0_8_ != (code *)0x0)) {
            FUN_23e91b1b0(param_1,auStack_b8,auStack_b8 + 8,apcStack_a8);
          }
          plVar14 = *(longlong **)(auStack_b8._8_8_ + 0x28);
          if (apcStack_a8[0] == pcVar23) {
            pcVar18 = (code *)0x0;
          }
          else {
            pcVar18 = apcStack_a8[0];
            if (apcStack_a8[0] != (code *)0x0) {
              *(longlong *)apcStack_a8[0] = *(longlong *)apcStack_a8[0] + 1;
            }
          }
          *(code **)(auStack_b8._8_8_ + 0x28) = pcVar18;
          if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
            (**(code **)(plVar14[1] + 0x30))();
          }
          plVar14 = *(longlong **)(param_1 + 0x138);
          *(undefined8 *)(param_1 + 0x138) = auStack_b8._8_8_;
          if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
            (**(code **)(plVar14[1] + 0x30))();
          }
          *(longlong *)auStack_b8._0_8_ = *(longlong *)auStack_b8._0_8_ + -1;
          if (*(longlong *)auStack_b8._0_8_ == 0) {
            (**(code **)(*(longlong *)(auStack_b8._0_8_ + 8) + 0x30))();
          }
          if ((apcStack_a8[0] != (code *)0x0) &&
             (*(longlong *)apcStack_a8[0] = *(longlong *)apcStack_a8[0] + -1,
             *(longlong *)apcStack_a8[0] == 0)) {
            (**(code **)(*(longlong *)(apcStack_a8[0] + 8) + 0x30))();
          }
          apcStack_a8[0] = (code *)0x0;
          auStack_b8 = (undefined1  [16])0x0;
          iVar8 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                                *(undefined8 *)PyExc_BaseException_exref);
          pcVar20 = *(code **)(param_1 + 0x138);
          if (iVar8 == 0) {
            pcStack_90 = pcVar20;
            if (pcVar20 == pcVar23) goto LAB_23c639dea;
            if (pcVar20 == (code *)0x0) goto LAB_23c639dea;
            auVar22 = *(undefined1 (*) [8])(pcVar20 + 8);
            pcVar18 = *(code **)(pcVar20 + 0x28);
            *(longlong *)pcVar20 = *(longlong *)pcVar20 + 1;
            *(longlong *)auVar22 = *(longlong *)auVar22 + 1;
            if (pcVar18 == (code *)0x0) {
              *(longlong **)(param_1 + 0x138) = plVar11;
              bVar5 = true;
              iVar8 = 0;
              pcVar19 = pcVar20;
              goto LAB_23c639197;
            }
            *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
            if (*(longlong **)(pcVar18 + 0x18) == plVar3) {
              *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(pcVar18 + 0x24);
            }
            bVar5 = true;
LAB_23c639175:
            *(longlong **)(param_1 + 0x138) = plVar11;
            iVar8 = 0;
            pcVar19 = pcVar20;
            goto LAB_23c639197;
          }
          pcStack_78 = *(code **)(pcVar20 + 8);
          pcStack_68 = *(code **)(pcVar20 + 0x28);
          *(undefined4 *)(plVar3 + 5) = 0x197;
          if (pcStack_68 == (code *)0x0) {
            pcStack_68 = pcVar23;
          }
          pcStack_70 = pcVar20;
          plVar14 = (longlong *)FUN_23e956150(param_1);
          if (plVar14 == (longlong *)0x0) {
            pcVar18 = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            bVar5 = false;
            pcVar19 = *(code **)(param_1 + 0x138);
            auVar22 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcVar20 = *(code **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23c639722;
          }
          iVar8 = FUN_23a35f020(plVar14);
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))();
          }
          if (iVar8 == -1) {
            auVar22 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcVar20 = *(code **)(param_1 + 0x68);
            bVar5 = false;
            pcVar18 = *(code **)(param_1 + 0x70);
            pcVar19 = *(code **)(param_1 + 0x138);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            goto LAB_23c639722;
          }
          if (iVar8 == 0) {
            pcVar20 = *(code **)(param_1 + 0x138);
            pcStack_90 = pcVar20;
            bVar5 = false;
            if ((pcVar20 == pcVar23) || (pcVar20 == (code *)0x0)) {
              auVar22 = *(undefined1 (*) [8])PyExc_RuntimeError_exref;
              pcVar20 = (code *)PyUnicode_FromString("No active exception to reraise");
              pcVar19 = *(code **)(param_1 + 0x138);
              pcVar18 = (code *)0x0;
              *(longlong *)auVar22 = *(longlong *)auVar22 + 1;
              goto LAB_23c639722;
            }
            auVar22 = *(undefined1 (*) [8])(pcVar20 + 8);
            pcVar18 = *(code **)(pcVar20 + 0x28);
            *(longlong *)pcVar20 = *(longlong *)pcVar20 + 1;
            *(longlong *)auVar22 = *(longlong *)auVar22 + 1;
            if (pcVar18 == (code *)0x0) {
              *(longlong **)(param_1 + 0x138) = plVar11;
              iVar8 = 0;
              pcVar19 = pcVar20;
              goto LAB_23c639197;
            }
            *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
            if (*(longlong **)(pcVar18 + 0x18) == plVar3) {
              *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(pcVar18 + 0x24);
            }
            goto LAB_23c639175;
          }
          plVar14 = *(longlong **)(param_1 + 0x138);
          *(longlong **)(param_1 + 0x138) = plVar11;
          if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
            (**(code **)(plVar14[1] + 0x30))();
          }
LAB_23c639818:
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) {
            (**(code **)(plVar12[1] + 0x30))(plVar12);
          }
          *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
          if (*(longlong *)pcVar13 == 0) {
            (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))(pcVar13);
          }
        }
        else {
          plVar14 = (longlong *)FUN_23a388310(plVar11);
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          if (plVar14 == (longlong *)0x0) goto LAB_23c638e40;
          plVar11 = (longlong *)(**(code **)(plVar14[1] + 0xe0))(plVar14);
          if (plVar11 == (longlong *)0x0) {
            plVar11 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,0,2);
            pcStack_118 = (code *)0x0;
            if (plVar11 != (longlong *)0x0) goto LAB_23c637c34;
LAB_23c6392e0:
            pcVar18 = apcStack_88[0];
            pcVar20 = pcStack_90;
            auVar22 = auStack_98;
            apcStack_88[0] = (code *)0x0;
            _auStack_98 = (undefined1  [16])0x0;
            *plVar14 = *plVar14 + -1;
            if (*plVar14 == 0) {
              (**(code **)(plVar14[1] + 0x30))(plVar14);
            }
            apcStack_88[0] = (code *)0x0;
            auStack_98 = (undefined1  [8])0x0;
            pcStack_90 = (code *)0x0;
            if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            if ((pcStack_118 != (code *)0x0) &&
               (lVar15 = *(longlong *)pcStack_118, *(longlong *)pcStack_118 = lVar15 + -1,
               lVar15 + -1 == 0)) {
              (**(code **)(*(longlong *)(pcStack_118 + 8) + 0x30))(pcStack_118);
            }
            goto LAB_23c638e59;
          }
LAB_23c637c34:
          pcStack_118 = (code *)(**(code **)(plVar14[1] + 0xe0))(plVar14);
          if (((pcStack_118 == (code *)0x0) &&
              (pcStack_118 = (code *)FUN_23a3c1b70(param_1,auStack_98,1,2),
              pcStack_118 == (code *)0x0)) ||
             (cVar7 = FUN_23a3884a0(param_1,auStack_98,plVar14,2), cVar7 == '\0'))
          goto LAB_23c6392e0;
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          lVar15 = *plVar11;
          *plVar11 = lVar15 + 1;
          if (plStack_120 != (longlong *)0x0) {
            lVar15 = *plStack_120;
            *plStack_120 = lVar15 + -1;
            if (lVar15 + -1 == 0) {
              (**(code **)(plStack_120[1] + 0x30))(plStack_120);
            }
            lVar15 = *plVar11 + -1;
          }
          *plVar11 = lVar15;
          if (lVar15 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          lVar15 = *(longlong *)pcStack_118;
          *(longlong *)pcStack_118 = lVar15 + 1;
          if (pcStack_128 != (code *)0x0) {
            lVar15 = *(longlong *)pcStack_128;
            *(longlong *)pcStack_128 = lVar15 + -1;
            if (lVar15 + -1 == 0) {
              (**(code **)(*(longlong *)(pcStack_128 + 8) + 0x30))(pcStack_128);
              lVar15 = *(longlong *)pcStack_118 + -1;
            }
            else {
              lVar15 = *(longlong *)pcStack_118 + -1;
            }
          }
          *(longlong *)pcStack_118 = lVar15;
          if (lVar15 == 0) {
            (**(code **)(*(longlong *)(pcStack_118 + 8) + 0x30))();
          }
          iVar8 = FUN_23a35f020(plVar11);
          plStack_120 = plVar11;
          if (iVar8 == -1) {
            apcStack_88[0] = *(code **)(param_1 + 0x70);
            auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
            *(undefined8 *)(param_1 + 0x70) = 0;
            pcStack_130 = _PyRuntime_exref;
            uVar21 = 0x19a;
            pcStack_128 = pcStack_118;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            pcStack_90 = *(code **)(param_1 + 0x68);
            goto LAB_23c638e7b;
          }
          if (iVar8 != 0) {
            iVar8 = PySequence_Contains(pcStack_118,_DAT_23ee28980);
            if (iVar8 == -1) {
              apcStack_88[0] = *(code **)(param_1 + 0x70);
              auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
              *(undefined8 *)(param_1 + 0x70) = 0;
              pcStack_130 = _PyRuntime_exref;
              uVar21 = 0x1a3;
              pcStack_128 = pcStack_118;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              pcStack_90 = *(code **)(param_1 + 0x68);
              goto LAB_23c638e7b;
            }
            if (iVar8 == 1) {
              lVar15 = FUN_23ead5f40();
              if (lVar15 == 0) {
                FUN_23e915740(param_1,auStack_98,DAT_23ee283f8);
                pcStack_130 = _PyRuntime_exref;
              }
              else {
                plVar11 = (longlong *)FUN_23e8bc2f0(lVar15,_DAT_23ee28548);
                plVar14 = _DAT_23ee28988;
                if (plVar11 == (longlong *)0x0) {
                  apcStack_88[0] = *(code **)(param_1 + 0x70);
                  auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  pcStack_130 = _PyRuntime_exref;
                  uVar21 = 0x1a4;
                  pcStack_128 = pcStack_118;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  pcStack_90 = *(code **)(param_1 + 0x68);
                  goto LAB_23c638e7b;
                }
                lVar15 = *(longlong *)(param_1 + 0x10);
                pcStack_128 = *(code **)(lVar15 + 0xe20);
                if (pcStack_128 == (code *)0x0) {
                  pcStack_128 = (code *)FUN_23e916a20(PyTuple_Type_exref,2);
                }
                else {
                  lVar9 = *(longlong *)(pcStack_128 + 0x18);
                  *(int *)(lVar15 + 0xebc) = *(int *)(lVar15 + 0xebc) + -1;
                  *(longlong *)(lVar15 + 0xe20) = lVar9;
                  *(longlong *)pcStack_128 = 1;
                }
                pcStack_130 = _PyRuntime_exref;
                *(longlong *)(pcStack_128 + 0x20) = 0;
                lVar15 = *(longlong *)
                          (*(longlong *)(*(longlong *)(pcStack_130 + 0x1f8) + 0x10) + 0x2e8);
                lVar9 = *(longlong *)(pcStack_128 + -8);
                puVar2 = *(undefined8 **)(lVar15 + 8);
                *puVar2 = pcStack_128 + -0x10;
                *(longlong *)(pcStack_128 + -0x10) = lVar15;
                *(ulonglong *)(pcStack_128 + -8) = (ulonglong)((uint)lVar9 & 3) | (ulonglong)puVar2;
                *(code **)(lVar15 + 8) = pcStack_128 + -0x10;
                plVar17 = DAT_23ed6a4c0;
                *plVar14 = *plVar14 + 1;
                *(longlong **)(pcStack_128 + 0x18) = plVar14;
                pcVar18 = DAT_23ed6cd28;
                if (plVar17 == (longlong *)0x0) {
                  plVar17 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                  if (plVar17 == (longlong *)0x0) goto LAB_23c639dd7;
                  *plVar17 = *plVar17 + 1;
                  DAT_23ed6a4c0 = plVar17;
                }
                pcStack_78 = pcStack_118;
                pcStack_70 = pcVar18;
                lVar15 = FUN_23e94ed00(param_1,plVar17,&pcStack_78);
                if (lVar15 == 0) {
                  auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pcStack_90 = *(code **)(param_1 + 0x68);
                  apcStack_88[0] = *(code **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    FUN_23a334bc0(plVar11);
                  }
                  *(longlong *)pcStack_128 = *(longlong *)pcStack_128 + -1;
                  if (*(longlong *)pcStack_128 == 0) {
                    FUN_23a334bc0(pcStack_128);
                  }
                }
                else {
                  *(longlong *)(pcStack_128 + 0x20) = lVar15;
                  plVar14 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,pcStack_128);
                  *(longlong *)pcStack_128 = *(longlong *)pcStack_128 + -1;
                  if (*(longlong *)pcStack_128 == 0) {
                    FUN_23a334bc0(pcStack_128);
                  }
                  if (plVar14 == (longlong *)0x0) {
                    auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pcStack_90 = *(code **)(param_1 + 0x68);
                    apcStack_88[0] = *(code **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar11 = *plVar11 + -1;
                    if (*plVar11 == 0) {
                      FUN_23a334bc0(plVar11);
                    }
                  }
                  else {
                    *(undefined4 *)(plVar3 + 5) = 0x1a4;
                    plVar17 = (longlong *)FUN_23e914090(param_1,plVar11,plVar14);
                    *plVar11 = *plVar11 + -1;
                    if (*plVar11 == 0) {
                      FUN_23a334bc0(plVar11);
                    }
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 == 0) {
                      FUN_23a334bc0(plVar14);
                    }
                    if (plVar17 != (longlong *)0x0) goto LAB_23c63a0cc;
                    apcStack_88[0] = *(code **)(param_1 + 0x70);
                    auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pcStack_90 = *(code **)(param_1 + 0x68);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  }
                }
              }
              uVar21 = 0x1a4;
              pcStack_128 = pcStack_118;
              goto LAB_23c638e7b;
            }
            lVar15 = FUN_23ead5f40();
            if (lVar15 == 0) {
              FUN_23e915740(param_1,auStack_98,DAT_23ee283f8);
              pcStack_130 = _PyRuntime_exref;
              goto LAB_23c63a693;
            }
            plVar11 = (longlong *)FUN_23e8bc2f0(lVar15,DAT_23ee28400);
            plVar14 = _DAT_23ee28990;
            if (plVar11 == (longlong *)0x0) {
              apcStack_88[0] = *(code **)(param_1 + 0x70);
              auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar21 = 0x1a6;
              pcStack_128 = pcStack_118;
              pcStack_130 = _PyRuntime_exref;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              pcStack_90 = *(code **)(param_1 + 0x68);
              goto LAB_23c638e7b;
            }
            lVar15 = *(longlong *)(param_1 + 0x10);
            pcStack_128 = *(code **)(lVar15 + 0xe20);
            if (pcStack_128 == (code *)0x0) {
              pcStack_128 = (code *)FUN_23e916a20(PyTuple_Type_exref,2);
            }
            else {
              lVar9 = *(longlong *)(pcStack_128 + 0x18);
              *(int *)(lVar15 + 0xebc) = *(int *)(lVar15 + 0xebc) + -1;
              *(longlong *)(lVar15 + 0xe20) = lVar9;
              *(longlong *)pcStack_128 = 1;
            }
            pcStack_130 = _PyRuntime_exref;
            *(longlong *)(pcStack_128 + 0x20) = 0;
            lVar15 = *(longlong *)(*(longlong *)(*(longlong *)(pcStack_130 + 0x1f8) + 0x10) + 0x2e8)
            ;
            lVar9 = *(longlong *)(pcStack_128 + -8);
            puVar2 = *(undefined8 **)(lVar15 + 8);
            *puVar2 = pcStack_128 + -0x10;
            *(longlong *)(pcStack_128 + -0x10) = lVar15;
            *(ulonglong *)(pcStack_128 + -8) = (ulonglong)((uint)lVar9 & 3) | (ulonglong)puVar2;
            *(code **)(lVar15 + 8) = pcStack_128 + -0x10;
            plVar17 = DAT_23ed6a4c0;
            *plVar14 = *plVar14 + 1;
            *(longlong **)(pcStack_128 + 0x18) = plVar14;
            pcVar18 = DAT_23ed6cd28;
            if (plVar17 == (longlong *)0x0) {
              plVar17 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
              if (plVar17 == (longlong *)0x0) goto LAB_23c639dd7;
              *plVar17 = *plVar17 + 1;
              DAT_23ed6a4c0 = plVar17;
            }
            pcStack_78 = pcStack_118;
            pcStack_70 = pcVar18;
            lVar15 = FUN_23e94ed00(param_1,plVar17,&pcStack_78);
            if (lVar15 == 0) {
              auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
              pcStack_90 = *(code **)(param_1 + 0x68);
              apcStack_88[0] = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
              *(longlong *)pcStack_128 = *(longlong *)pcStack_128 + -1;
              if (*(longlong *)pcStack_128 == 0) {
                (**(code **)(*(longlong *)(pcStack_128 + 8) + 0x30))(pcStack_128);
              }
LAB_23c63a693:
              uVar21 = 0x1a6;
              pcStack_128 = pcStack_118;
              goto LAB_23c638e7b;
            }
            *(longlong *)(pcStack_128 + 0x20) = lVar15;
            plVar14 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,pcStack_128);
            *(longlong *)pcStack_128 = *(longlong *)pcStack_128 + -1;
            if (*(longlong *)pcStack_128 == 0) {
              (**(code **)(*(longlong *)(pcStack_128 + 8) + 0x30))(pcStack_128);
            }
            if (plVar14 == (longlong *)0x0) {
              auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
              pcStack_90 = *(code **)(param_1 + 0x68);
              apcStack_88[0] = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                FUN_23a334bc0(plVar11);
              }
              goto LAB_23c63a693;
            }
            *(undefined4 *)(plVar3 + 5) = 0x1a6;
            plVar17 = (longlong *)FUN_23e914090(param_1,plVar11,plVar14);
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            *plVar14 = *plVar14 + -1;
            if (*plVar14 == 0) {
              (**(code **)(plVar14[1] + 0x30))(plVar14);
            }
            if (plVar17 == (longlong *)0x0) {
              auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
              pcStack_90 = *(code **)(param_1 + 0x68);
              apcStack_88[0] = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23c63a693;
            }
LAB_23c63a0cc:
            *plVar17 = *plVar17 + -1;
            if (*plVar17 == 0) {
              FUN_23a334bc0(plVar17);
            }
            *(undefined4 *)(plVar3 + 5) = 0x197;
            plVar11 = (longlong *)FUN_23e957a30(param_1,pcVar13,_DAT_23ee284b0);
            if (plVar11 == (longlong *)0x0) goto LAB_23c637f9b;
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              FUN_23a334bc0();
            }
            pcStack_128 = pcStack_118;
            goto LAB_23c639818;
          }
          lVar15 = FUN_23ead5f40();
          if (lVar15 == 0) {
            FUN_23e915740(param_1,auStack_98,DAT_23ee283f8);
            pcStack_130 = _PyRuntime_exref;
LAB_23c63a34e:
            pcStack_128 = pcStack_118;
            uVar21 = 0x19b;
            goto LAB_23c638e7b;
          }
          pcStack_128 = (code *)FUN_23e8bc2f0(lVar15,DAT_23ee284c0);
          plVar14 = _DAT_23ee28978;
          if (pcStack_128 == (code *)0x0) {
            apcStack_88[0] = *(code **)(param_1 + 0x70);
            auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_90 = *(code **)(param_1 + 0x68);
            *(undefined8 *)(param_1 + 0x70) = 0;
            pcStack_130 = _PyRuntime_exref;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23c63a34e;
          }
          lVar15 = *(longlong *)(param_1 + 0x10);
          plVar11 = *(longlong **)(lVar15 + 0xe20);
          if (plVar11 == (longlong *)0x0) {
            plVar11 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
          }
          else {
            lVar9 = plVar11[3];
            *(int *)(lVar15 + 0xebc) = *(int *)(lVar15 + 0xebc) + -1;
            *(longlong *)(lVar15 + 0xe20) = lVar9;
            *plVar11 = 1;
          }
          pcStack_130 = _PyRuntime_exref;
          plVar11[4] = 0;
          lVar15 = *(longlong *)(*(longlong *)(*(longlong *)(pcStack_130 + 0x1f8) + 0x10) + 0x2e8);
          lVar9 = plVar11[-1];
          puVar2 = *(undefined8 **)(lVar15 + 8);
          *puVar2 = plVar11 + -2;
          plVar11[-2] = lVar15;
          plVar11[-1] = (ulonglong)((uint)lVar9 & 3) | (ulonglong)puVar2;
          *(longlong **)(lVar15 + 8) = plVar11 + -2;
          plVar17 = DAT_23ed6a4c0;
          *plVar14 = *plVar14 + 1;
          plVar11[3] = (longlong)plVar14;
          pcVar18 = DAT_23ed6cd28;
          if (plVar17 == (longlong *)0x0) {
            plVar17 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
            if (plVar17 == (longlong *)0x0) goto LAB_23c639dd7;
            *plVar17 = *plVar17 + 1;
            DAT_23ed6a4c0 = plVar17;
          }
          pcStack_78 = pcStack_118;
          pcStack_70 = pcVar18;
          lVar15 = FUN_23e94ed00(param_1,plVar17,&pcStack_78);
          if (lVar15 == 0) {
            auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_90 = *(code **)(param_1 + 0x68);
            apcStack_88[0] = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(longlong *)pcStack_128 = *(longlong *)pcStack_128 + -1;
            if (*(longlong *)pcStack_128 == 0) {
              (**(code **)(*(longlong *)(pcStack_128 + 8) + 0x30))(pcStack_128);
            }
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            goto LAB_23c63a34e;
          }
          plVar11[4] = lVar15;
          plVar14 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar11);
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          if (plVar14 == (longlong *)0x0) {
            auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_90 = *(code **)(param_1 + 0x68);
            apcStack_88[0] = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(longlong *)pcStack_128 = *(longlong *)pcStack_128 + -1;
            if (*(longlong *)pcStack_128 == 0) {
              FUN_23a334bc0(pcStack_128);
            }
            goto LAB_23c63a34e;
          }
          *(undefined4 *)(plVar3 + 5) = 0x19b;
          plVar11 = (longlong *)FUN_23e914090(param_1,pcStack_128,plVar14);
          *(longlong *)pcStack_128 = *(longlong *)pcStack_128 + -1;
          if (*(longlong *)pcStack_128 == 0) {
            (**(code **)(*(longlong *)(pcStack_128 + 8) + 0x30))(pcStack_128);
          }
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          if (plVar11 == (longlong *)0x0) {
            auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_90 = *(code **)(param_1 + 0x68);
            apcStack_88[0] = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23c63a34e;
          }
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          *(undefined4 *)(plVar3 + 5) = 0x197;
          plVar11 = (longlong *)FUN_23e957a30(param_1,pcVar13,_DAT_23ee284b0);
          if (plVar11 != (longlong *)0x0) {
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              FUN_23a334bc0();
            }
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              FUN_23a334bc0(plVar10);
            }
            lVar15 = *plVar12;
            *plVar12 = lVar15 + -1;
            if (lVar15 + -1 == 0) {
              FUN_23a334bc0(plVar12);
            }
            *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
            if (*(longlong *)pcVar13 == 0) {
              FUN_23a334bc0(pcVar13);
            }
            pcStack_128 = pcStack_118;
            goto LAB_23c639af9;
          }
LAB_23c637f9b:
          auVar22 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcVar18 = *(code **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          pcVar23 = _Py_NoneStruct_exref;
          iVar8 = 0x197;
          *(undefined8 *)(param_1 + 0x70) = 0;
          pcStack_128 = pcStack_118;
          pcVar20 = *(code **)(param_1 + 0x68);
LAB_23c639240:
          apcStack_88[0] = (code *)0x0;
          auStack_98 = (undefined1  [8])0x0;
          pcStack_90 = (code *)0x0;
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
LAB_23c6393ed:
            pcStack_90 = (code *)0x0;
            auStack_98 = (undefined1  [8])0x0;
            apcStack_88[0] = (code *)0x0;
            (**(code **)(plVar10[1] + 0x30))();
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) goto LAB_23c639269;
LAB_23c63927d:
            if (pcVar13 != (code *)0x0) goto LAB_23c639286;
          }
          else {
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
LAB_23c639269:
              (**(code **)(plVar12[1] + 0x30))();
              goto LAB_23c63927d;
            }
LAB_23c639286:
            *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
            if (*(longlong *)pcVar13 == 0) {
              (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))();
            }
          }
LAB_23c638030:
          pcStack_90 = pcVar20;
          auStack_98 = auVar22;
          apcStack_88[0] = pcVar18;
          pcVar18 = apcStack_88[0];
          auStack_f8._8_8_ = pcStack_90;
          auStack_f8._0_8_ = auStack_98;
          apcStack_88[0] = (code *)0x0;
          plVar11 = *(longlong **)(param_1 + 0x138);
          auStack_98 = (undefined1  [8])0x0;
          pcStack_90 = (code *)0x0;
          apcStack_e8[0] = pcVar18;
          if (plVar11 != (longlong *)0x0) {
            *plVar11 = *plVar11 + 1;
          }
          pcVar20 = DAT_23ed6a4f8;
          if (pcVar18 == (code *)0x0) {
            if (iVar8 == 0) {
              iVar8 = (int)plVar3[5];
            }
            if (DAT_23ed6a4f8 == (code *)0x0) {
              pcVar20 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
              pcVar18 = apcStack_e8[0];
            }
            else {
              pcVar18 = *(code **)DAT_23ed6a4f8;
              *(longlong *)DAT_23ed6a4f8 = 1;
              DAT_23ed6a4f8 = pcVar18;
              DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
              pcVar18 = (code *)0x0;
            }
            pcVar13 = _PyRuntime_exref;
            *(longlong **)(pcVar20 + 0x18) = plVar3;
            *(longlong *)(pcVar20 + 0x10) = 0;
            *plVar3 = *plVar3 + 1;
            lVar15 = *(longlong *)(pcVar13 + 0x1f8);
            *(int *)(pcVar20 + 0x24) = iVar8;
            *(undefined4 *)(pcVar20 + 0x20) = 0xffffffff;
            lVar15 = *(longlong *)(*(longlong *)(lVar15 + 0x10) + 0x2e8);
            lVar9 = *(longlong *)(pcVar20 + -8);
            puVar2 = *(undefined8 **)(lVar15 + 8);
            *puVar2 = pcVar20 + -0x10;
            *(longlong *)(pcVar20 + -0x10) = lVar15;
            *(ulonglong *)(pcVar20 + -8) = (ulonglong)((uint)lVar9 & 3) | (ulonglong)puVar2;
            *(code **)(lVar15 + 8) = pcVar20 + -0x10;
            pcVar13 = pcVar20;
            if ((pcVar18 != (code *)0x0) &&
               (*(longlong *)pcVar18 = *(longlong *)pcVar18 + -1, *(longlong *)pcVar18 == 0)) {
              (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))();
            }
          }
          else {
            pcVar13 = apcStack_e8[0];
            if (iVar8 != 0) {
              if (DAT_23ed6a4f8 == (code *)0x0) {
                pcVar20 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
              }
              else {
                pcVar13 = *(code **)DAT_23ed6a4f8;
                *(longlong *)DAT_23ed6a4f8 = 1;
                DAT_23ed6a4f8 = pcVar13;
                DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
              }
              pcVar13 = _PyRuntime_exref;
              *(longlong **)(pcVar20 + 0x18) = plVar3;
              *plVar3 = *plVar3 + 1;
              lVar15 = *(longlong *)(pcVar13 + 0x1f8);
              *(int *)(pcVar20 + 0x24) = iVar8;
              *(undefined4 *)(pcVar20 + 0x20) = 0xffffffff;
              lVar15 = *(longlong *)(*(longlong *)(lVar15 + 0x10) + 0x2e8);
              lVar9 = *(longlong *)(pcVar20 + -8);
              puVar2 = *(undefined8 **)(lVar15 + 8);
              *puVar2 = pcVar20 + -0x10;
              *(longlong *)(pcVar20 + -0x10) = lVar15;
              *(ulonglong *)(pcVar20 + -8) = (ulonglong)((uint)lVar9 & 3) | (ulonglong)puVar2;
              *(code **)(lVar15 + 8) = pcVar20 + -0x10;
              *(code **)(pcVar20 + 0x10) = pcVar18;
              *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
              pcVar13 = pcVar20;
              if ((apcStack_e8[0] != (code *)0x0) &&
                 (*(longlong *)apcStack_e8[0] = *(longlong *)apcStack_e8[0] + -1,
                 *(longlong *)apcStack_e8[0] == 0)) {
                (**(code **)(*(longlong *)(apcStack_e8[0] + 8) + 0x30))();
              }
            }
          }
          apcStack_e8[0] = pcVar13;
          if (((code *)auStack_f8._0_8_ != pcVar23) && ((code *)auStack_f8._0_8_ != (code *)0x0)) {
            FUN_23e91b1b0(param_1,auStack_f8,auStack_f8 + 8,apcStack_e8);
          }
          plVar10 = *(longlong **)(auStack_f8._8_8_ + 0x28);
          if (apcStack_e8[0] == pcVar23) {
            pcVar18 = (code *)0x0;
          }
          else {
            pcVar18 = apcStack_e8[0];
            if (apcStack_e8[0] != (code *)0x0) {
              *(longlong *)apcStack_e8[0] = *(longlong *)apcStack_e8[0] + 1;
            }
          }
          *(code **)(auStack_f8._8_8_ + 0x28) = pcVar18;
          if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
            (**(code **)(plVar10[1] + 0x30))();
          }
          plVar10 = *(longlong **)(param_1 + 0x138);
          *(undefined8 *)(param_1 + 0x138) = auStack_f8._8_8_;
          if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
            (**(code **)(plVar10[1] + 0x30))();
          }
          *(longlong *)auStack_f8._0_8_ = *(longlong *)auStack_f8._0_8_ + -1;
          if (*(longlong *)auStack_f8._0_8_ == 0) {
            (**(code **)(*(longlong *)(auStack_f8._0_8_ + 8) + 0x30))();
          }
          if ((apcStack_e8[0] != (code *)0x0) &&
             (*(longlong *)apcStack_e8[0] = *(longlong *)apcStack_e8[0] + -1,
             *(longlong *)apcStack_e8[0] == 0)) {
            (**(code **)(*(longlong *)(apcStack_e8[0] + 8) + 0x30))();
          }
          pcVar20 = *(code **)(param_1 + 0x138);
          apcStack_e8[0] = (code *)0x0;
          auStack_f8 = (undefined1  [16])0x0;
          pcVar18 = *(code **)PyExc_Exception_exref;
          pcVar19 = *(code **)(pcVar20 + 8);
          if ((*(uint *)(*(longlong *)(pcVar18 + 8) + 0xa8) & 0x4000000) == 0) {
            if (((int)*(uint *)(*(longlong *)(pcVar18 + 8) + 0xa8) < 0) &&
               (((byte)pcVar18[0xab] & 0x40) != 0)) {
              pcVar4 = *(code **)(pcVar19 + 8);
              pcVar13 = pcVar20;
              if ((*(uint *)(pcVar4 + 0xa8) & 0x40000000) == 0) {
                pcVar6 = pcVar19;
                if (((int)*(uint *)(pcVar4 + 0xa8) < 0) && (((byte)pcVar19[0xab] & 0x40) != 0))
                goto LAB_23c638882;
              }
              else {
                pcVar19 = pcVar4;
                pcVar6 = pcVar4;
                if (*(int *)(*(longlong *)(pcVar4 + 8) + 0xa8) < 0) {
LAB_23c638882:
                  lVar15 = *(longlong *)(pcVar19 + 0x158);
                  if (lVar15 != 0) {
                    if (*(longlong *)(lVar15 + 0x10) < 1) goto LAB_23c638217;
                    lVar9 = 0;
                    while (pcVar18 != *(code **)(lVar15 + 0x18 + lVar9 * 8)) {
                      lVar9 = lVar9 + 1;
                      if (*(longlong *)(lVar15 + 0x10) == lVar9) goto LAB_23c638217;
                    }
                    goto LAB_23c638375;
                  }
                  do {
                    if (pcVar18 == pcVar19) goto LAB_23c638375;
                    pcVar19 = *(code **)(pcVar19 + 0x100);
                    pcVar6 = PyBaseObject_Type_exref;
                  } while (pcVar19 != (code *)0x0);
                }
              }
              if (pcVar6 != pcVar18) goto LAB_23c638217;
            }
            else {
LAB_23c6382f0:
              plVar10 = *(longlong **)PyExc_TypeError_exref;
              uVar16 = PyUnicode_FromString
                                 (
                                 "catching classes that do not inherit from BaseException is not allowed"
                                 );
              plVar12 = *(longlong **)(param_1 + 0x60);
              plVar14 = *(longlong **)(param_1 + 0x68);
              plVar17 = *(longlong **)(param_1 + 0x70);
              *(longlong **)(param_1 + 0x60) = plVar10;
              *plVar10 = *plVar10 + 1;
              *(undefined8 *)(param_1 + 0x68) = uVar16;
              *(undefined8 *)(param_1 + 0x70) = 0;
              if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
                (**(code **)(plVar12[1] + 0x30))();
              }
              if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
                (**(code **)(plVar14[1] + 0x30))(plVar14);
              }
              if ((plVar17 == (longlong *)0x0) || (*plVar17 = *plVar17 + -1, *plVar17 != 0))
              goto LAB_23c638830;
              (**(code **)(plVar17[1] + 0x30))(plVar17);
              pcVar13 = *(code **)(param_1 + 0x138);
            }
          }
          else {
            lVar15 = *(longlong *)(pcVar18 + 0x10);
            if (lVar15 < 1) {
LAB_23c638217:
              pcStack_90 = pcVar20;
              if ((pcVar20 == pcVar23) || (pcVar20 == (code *)0x0)) {
                pcVar18 = (code *)0x0;
                iVar8 = 0x195;
                auVar22 = *(undefined1 (*) [8])PyExc_RuntimeError_exref;
                pcVar20 = (code *)PyUnicode_FromString("No active exception to reraise");
                pcVar23 = *(code **)(param_1 + 0x138);
                *(longlong *)auVar22 = *(longlong *)auVar22 + 1;
                goto LAB_23c638bc8;
              }
              auVar22 = *(undefined1 (*) [8])(pcVar20 + 8);
              pcVar18 = *(code **)(pcVar20 + 0x28);
              *(longlong *)pcVar20 = *(longlong *)pcVar20 + 1;
              *(longlong *)auVar22 = *(longlong *)auVar22 + 1;
              pcVar23 = pcVar20;
              if (pcVar18 == (code *)0x0) {
                iVar8 = 0;
                *(longlong **)(param_1 + 0x138) = plVar11;
              }
              else {
                *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
                if (*(longlong **)(pcVar18 + 0x18) == plVar3) {
                  *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(pcVar18 + 0x24);
                }
                iVar8 = 0;
                *(longlong **)(param_1 + 0x138) = plVar11;
              }
              goto LAB_23c638bf5;
            }
            lVar9 = 0;
            do {
              if ((-1 < *(int *)(*(longlong *)(*(longlong *)(pcVar18 + lVar9 * 8 + 0x18) + 8) + 0xa8
                                )) ||
                 ((*(byte *)(*(longlong *)(pcVar18 + lVar9 * 8 + 0x18) + 0xab) & 0x40) == 0))
              goto LAB_23c6382f0;
              lVar9 = lVar9 + 1;
            } while (lVar15 != lVar9);
            lVar9 = 0;
            while (iVar8 = FUN_23a35ebd0(param_1,pcVar19,*(undefined8 *)(pcVar18 + lVar9 * 8 + 0x18)
                                        ), iVar8 == 0) {
              lVar9 = lVar9 + 1;
              if (lVar15 == lVar9) {
                pcVar20 = *(code **)(param_1 + 0x138);
                goto LAB_23c638217;
              }
            }
LAB_23c638830:
            pcVar13 = *(code **)(param_1 + 0x138);
          }
LAB_23c638375:
          *(longlong *)pcVar13 = *(longlong *)pcVar13 + 1;
          lVar15 = FUN_23ead5f40();
          if (lVar15 == 0) {
            FUN_23e915740(param_1,auStack_98,DAT_23ee283f8);
            auVar22 = auStack_98;
            pcVar20 = pcStack_90;
            pcVar18 = apcStack_88[0];
            goto LAB_23c638b99;
          }
          plVar10 = (longlong *)FUN_23e8bc2f0(lVar15,DAT_23ee284c0);
          plVar14 = _DAT_23ee28998;
          if (plVar10 == (longlong *)0x0) goto LAB_23c639778;
          lVar15 = *(longlong *)(param_1 + 0x10);
          plVar12 = *(longlong **)(lVar15 + 0xe20);
          if (plVar12 == (longlong *)0x0) {
            plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
          }
          else {
            lVar9 = plVar12[3];
            *(int *)(lVar15 + 0xebc) = *(int *)(lVar15 + 0xebc) + -1;
            *(longlong *)(lVar15 + 0xe20) = lVar9;
            *plVar12 = 1;
          }
          pcStack_130 = _PyRuntime_exref;
          plVar12[4] = 0;
          lVar15 = *(longlong *)(*(longlong *)(*(longlong *)(pcStack_130 + 0x1f8) + 0x10) + 0x2e8);
          lVar9 = plVar12[-1];
          puVar2 = *(undefined8 **)(lVar15 + 8);
          *puVar2 = plVar12 + -2;
          plVar12[-2] = lVar15;
          plVar12[-1] = (ulonglong)((uint)lVar9 & 3) | (ulonglong)puVar2;
          *(longlong **)(lVar15 + 8) = plVar12 + -2;
          plVar17 = DAT_23ed6a4c0;
          *plVar14 = *plVar14 + 1;
          plVar12[3] = (longlong)plVar14;
          pcVar18 = DAT_23ed6cd28;
          if (plVar17 != (longlong *)0x0) goto LAB_23c638454;
          plVar17 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
          if (plVar17 == (longlong *)0x0) {
LAB_23c639dd7:
            pcVar23 = (code *)&DAT_23ed6cce0;
            PyErr_PrintEx(0);
            Py_Exit(1);
LAB_23c639dea:
            auVar22 = *(undefined1 (*) [8])PyExc_RuntimeError_exref;
            pcVar20 = (code *)PyUnicode_FromString("No active exception to reraise");
            pcVar18 = (code *)0x0;
            pcVar19 = *(code **)(param_1 + 0x138);
            bVar5 = true;
            *(longlong *)auVar22 = *(longlong *)auVar22 + 1;
LAB_23c639722:
            *(longlong **)(param_1 + 0x138) = plVar11;
            iVar8 = 0x197;
            if (pcVar19 != (code *)0x0) {
LAB_23c639197:
              apcStack_88[0] = (code *)0x0;
              _auStack_98 = (undefined1  [16])0x0;
              *(longlong *)pcVar19 = *(longlong *)pcVar19 + -1;
              if (*(longlong *)pcVar19 == 0) {
                (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))();
              }
            }
            apcStack_88[0] = (code *)0x0;
            _auStack_98 = (undefined1  [16])0x0;
            pcStack_d8 = (code *)auVar22;
            pcStack_d0 = pcVar20;
            pcStack_c8 = pcVar18;
            if (bVar5) {
              *(undefined4 *)(plVar3 + 5) = 0x197;
              plVar11 = (longlong *)FUN_23e957a30(param_1,pcVar13,_DAT_23ee284b0);
              if (plVar11 == (longlong *)0x0) {
                apcStack_88[0] = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
                pcStack_90 = *(code **)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                FUN_23a35d6b0();
                iVar8 = 0x197;
                pcVar18 = apcStack_88[0];
                auVar22 = auStack_98;
                pcVar20 = pcStack_90;
              }
              else {
                *plVar11 = *plVar11 + -1;
                pcVar18 = pcStack_c8;
                auVar22 = (undefined1  [8])pcStack_d8;
                pcVar20 = pcStack_d0;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))();
                  pcVar18 = pcStack_c8;
                  auVar22 = (undefined1  [8])pcStack_d8;
                  pcVar20 = pcStack_d0;
                }
              }
            }
            goto LAB_23c639240;
          }
          *plVar17 = *plVar17 + 1;
          DAT_23ed6a4c0 = plVar17;
LAB_23c638454:
          pcStack_70 = pcVar18;
          pcStack_78 = pcVar13;
          lVar15 = FUN_23e94ed00(param_1,plVar17,&pcStack_78);
          if (lVar15 == 0) {
            auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_90 = *(code **)(param_1 + 0x68);
            apcStack_88[0] = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            *plVar12 = *plVar12 + -1;
            auVar22 = auStack_98;
            pcVar20 = pcStack_90;
            pcVar18 = apcStack_88[0];
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
              auVar22 = auStack_98;
              pcVar20 = pcStack_90;
              pcVar18 = apcStack_88[0];
            }
LAB_23c638b99:
            apcStack_88[0] = (code *)0x0;
            _auStack_98 = (undefined1  [16])0x0;
            *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
            if (*(longlong *)pcVar13 == 0) {
              (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))(pcVar13);
            }
            pcVar23 = *(code **)(param_1 + 0x138);
            iVar8 = 0x1a9;
LAB_23c638bc8:
            *(longlong **)(param_1 + 0x138) = plVar11;
            if (pcVar23 == (code *)0x0) {
              apcStack_88[0] = pcVar18;
              auStack_98 = auVar22;
              pcStack_90 = pcVar20;
              if (pcVar18 == (code *)0x0) goto LAB_23c639439;
            }
            else {
LAB_23c638bf5:
              apcStack_88[0] = (code *)0x0;
              _auStack_98 = (undefined1  [16])0x0;
              *(longlong *)pcVar23 = *(longlong *)pcVar23 + -1;
              if (*(longlong *)pcVar23 == 0) {
                (**(code **)(*(longlong *)(pcVar23 + 8) + 0x30))(pcVar23);
              }
              auStack_98 = auVar22;
              pcStack_90 = pcVar20;
              if (pcVar18 == (code *)0x0) {
                apcStack_88[0] = pcVar18;
                if (iVar8 != 0) goto LAB_23c639439;
                pcStack_130 = _PyRuntime_exref;
                iVar8 = (int)plVar3[5];
                goto LAB_23c639445;
              }
            }
            if (*(longlong **)(pcVar18 + 0x18) == plVar3) goto LAB_23c6386f0;
            apcStack_88[0] = pcVar18;
            if (iVar8 != 0) goto LAB_23c6396e7;
            iVar8 = (int)plVar3[5];
            pcStack_130 = _PyRuntime_exref;
            goto LAB_23c638c43;
          }
          plVar12[4] = lVar15;
          plVar14 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar12);
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) {
            (**(code **)(plVar12[1] + 0x30))(plVar12);
          }
          if (plVar14 == (longlong *)0x0) {
            auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_90 = *(code **)(param_1 + 0x68);
            apcStack_88[0] = *(code **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *plVar10 = *plVar10 + -1;
            auVar22 = auStack_98;
            pcVar20 = pcStack_90;
            pcVar18 = apcStack_88[0];
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
              auVar22 = auStack_98;
              pcVar20 = pcStack_90;
              pcVar18 = apcStack_88[0];
            }
            goto LAB_23c638b99;
          }
          *(undefined4 *)(plVar3 + 5) = 0x1a9;
          plVar12 = (longlong *)FUN_23e914090(param_1,plVar10,plVar14);
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          if (plVar12 == (longlong *)0x0) {
LAB_23c639778:
            auVar22 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcVar18 = *(code **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            pcVar20 = *(code **)(param_1 + 0x68);
            goto LAB_23c638b99;
          }
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) {
            (**(code **)(plVar12[1] + 0x30))(plVar12);
          }
          *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
          if (*(longlong *)pcVar13 == 0) {
            (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))(pcVar13);
          }
          plVar10 = *(longlong **)(param_1 + 0x138);
          *(longlong **)(param_1 + 0x138) = plVar11;
          if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
            (**(code **)(plVar10[1] + 0x30))();
          }
        }
        plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23ee283d0);
        if (plVar10 == (longlong *)0x0) {
          auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_90 = *(code **)(param_1 + 0x68);
          apcStack_88[0] = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (apcStack_88[0] == (code *)0x0) goto LAB_23c639dcc;
LAB_23c639d38:
          iVar8 = 0x1ac;
          plVar10 = *(longlong **)(apcStack_88[0] + 0x18);
          goto joined_r0x00023c6397e9;
        }
        plVar11 = (longlong *)FUN_23e8bc2f0(plVar10,_DAT_23ee289a0);
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if (plVar11 == (longlong *)0x0) {
LAB_23c6397a8:
          auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_90 = *(code **)(param_1 + 0x68);
          apcStack_88[0] = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (apcStack_88[0] == (code *)0x0) {
LAB_23c639dcc:
            iVar8 = 0x1ac;
            goto LAB_23c639445;
          }
LAB_23c6397df:
          iVar8 = 0x1ac;
          plVar10 = *(longlong **)(apcStack_88[0] + 0x18);
          goto joined_r0x00023c6397e9;
        }
        plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23ee28900);
        if (plVar10 == (longlong *)0x0) {
          auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_90 = *(code **)(param_1 + 0x68);
          apcStack_88[0] = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
            if (apcStack_88[0] != (code *)0x0) goto LAB_23c639d38;
          }
          else if (apcStack_88[0] != (code *)0x0) goto LAB_23c6397df;
          goto LAB_23c639dcc;
        }
        *(undefined4 *)(plVar3 + 5) = 0x1ac;
        plVar12 = (longlong *)FUN_23e914090(param_1,plVar11,plVar10);
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if (plVar12 == (longlong *)0x0) goto LAB_23c6397a8;
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        lVar15 = *(longlong *)(param_1 + 0x10);
        if ((((*(int *)(*(longlong *)(lVar15 + 0x28) + 0x160) != 0) ||
             (*(int *)(lVar15 + 0x78) != 0)) && (iVar8 = Py_MakePendingCalls(), iVar8 < 0)) &&
           (pcVar18 = *(code **)(param_1 + 0x60), pcVar18 != (code *)0x0)) goto LAB_23c63869e;
        if (*(int *)(lVar15 + 0x68) != 0) {
          PyEval_SaveThread();
          PyEval_AcquireThread(param_1);
          plVar10 = *(longlong **)(param_1 + 0x90);
          if (plVar10 != (longlong *)0x0) break;
          goto LAB_23c637a54;
        }
        plVar10 = *(longlong **)(param_1 + 0x90);
      } while (plVar10 == (longlong *)0x0);
      plVar11 = *(longlong **)(param_1 + 0x60);
      plVar12 = *(longlong **)(param_1 + 0x68);
      *(undefined8 *)(param_1 + 0x90) = 0;
      plVar14 = *(longlong **)(param_1 + 0x70);
      *(longlong **)(param_1 + 0x60) = plVar10;
      *plVar10 = *plVar10 + 1;
      *(undefined8 *)(param_1 + 0x68) = 0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
        (**(code **)(plVar11[1] + 0x30))();
      }
      if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      pcVar18 = *(code **)(param_1 + 0x60);
LAB_23c63869e:
      apcStack_88[0] = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcStack_90 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      auStack_98 = (undefined1  [8])pcVar18;
      if (apcStack_88[0] == (code *)0x0) {
        iVar8 = 0x194;
        goto LAB_23c639445;
      }
      iVar8 = 0x194;
      plVar10 = *(longlong **)(apcStack_88[0] + 0x18);
joined_r0x00023c6397e9:
      pcVar18 = apcStack_88[0];
      if (plVar10 == plVar3) goto LAB_23c6386f0;
      goto LAB_23c638c43;
    }
    pcStack_90 = (code *)PyUnicode_FromFormat
                                   ("cannot access local variable \'%U\' where it is not associated with a value"
                                    ,_DAT_23ee28958);
    auStack_98 = *(undefined1 (*) [8])PyExc_UnboundLocalError_exref;
    *(longlong *)auStack_98 = *(longlong *)auStack_98 + 1;
    apcStack_88[0] = (code *)0x0;
    if (auStack_98 != (undefined1  [8])_Py_NoneStruct_exref) {
      FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,apcStack_88);
    }
    FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pcStack_90);
    if (apcStack_88[0] != (code *)0x0) {
      if (*(longlong **)(apcStack_88[0] + 0x18) != plVar3) {
        pcStack_128 = (code *)0x0;
        plStack_120 = (longlong *)0x0;
LAB_23c6396e1:
        iVar8 = 0x194;
LAB_23c6396e7:
        pcStack_130 = _PyRuntime_exref;
        goto LAB_23c638c43;
      }
      goto LAB_23c639688;
    }
    pcStack_128 = (code *)0x0;
    plStack_120 = (longlong *)0x0;
LAB_23c639e72:
    iVar8 = 0x194;
LAB_23c639439:
    pcStack_130 = _PyRuntime_exref;
LAB_23c639445:
    pcVar18 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar18 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      pcVar20 = apcStack_88[0];
    }
    else {
      pcVar20 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar20;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      pcVar20 = (code *)0x0;
    }
    *(longlong **)(pcVar18 + 0x18) = plVar3;
    *(longlong *)(pcVar18 + 0x10) = 0;
    *plVar3 = *plVar3 + 1;
    lVar15 = *(longlong *)(pcStack_130 + 0x1f8);
    *(undefined4 *)(pcVar18 + 0x20) = 0xffffffff;
    lVar15 = *(longlong *)(lVar15 + 0x10);
    *(int *)(pcVar18 + 0x24) = iVar8;
    lVar15 = *(longlong *)(lVar15 + 0x2e8);
    lVar9 = *(longlong *)(pcVar18 + -8);
    puVar2 = *(undefined8 **)(lVar15 + 8);
    *puVar2 = pcVar18 + -0x10;
    *(longlong *)(pcVar18 + -0x10) = lVar15;
    *(ulonglong *)(pcVar18 + -8) = (ulonglong)((uint)lVar9 & 3) | (ulonglong)puVar2;
    *(code **)(lVar15 + 8) = pcVar18 + -0x10;
  }
  if ((pcVar20 != (code *)0x0) &&
     (*(longlong *)pcVar20 = *(longlong *)pcVar20 + -1, *(longlong *)pcVar20 == 0)) {
    (**(code **)(*(longlong *)(pcVar20 + 8) + 0x30))();
  }
LAB_23c6386f0:
  apcStack_88[0] = pcVar18;
  FUN_23e8bba40(plVar3,&DAT_23ec47919,plVar1,plStack_120,pcStack_128,0);
  if (_DAT_23ee29c40 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23ee29c40 = (longlong *)0x0;
  }
  lVar15 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar10 = *(longlong **)(lVar15 + 0x28);
  plVar3 = (longlong *)plVar10[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar15 + 0x30);
  *(undefined4 *)(plVar10 + 8) = 0xffffffff;
  if (plVar3 != (longlong *)0x0) {
    plVar10[2] = 0;
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))();
    }
  }
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  pcVar20 = apcStack_88[0];
  pcVar18 = pcStack_90;
  auVar22 = auStack_98;
  plVar10[0xf] = 0;
  _auStack_98 = (undefined1  [16])0x0;
  apcStack_88[0] = (code *)0x0;
  if ((plStack_120 != (longlong *)0x0) && (*plStack_120 = *plStack_120 + -1, *plStack_120 == 0)) {
    (**(code **)(plStack_120[1] + 0x30))(plStack_120);
  }
  if ((pcStack_128 != (code *)0x0) &&
     (lVar15 = *(longlong *)pcStack_128, *(longlong *)pcStack_128 = lVar15 + -1, lVar15 + -1 == 0))
  {
    (**(code **)(*(longlong *)(pcStack_128 + 8) + 0x30))(pcStack_128);
  }
  *plVar1 = *plVar1 + -1;
  apcStack_88[0] = pcVar20;
  auStack_98 = auVar22;
  pcStack_90 = pcVar18;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,auStack_98,pcStack_90,apcStack_88[0]);
  return (code *)0x0;
}
